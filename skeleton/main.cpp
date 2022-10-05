#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>
#include <list>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include <iostream>

#include "Particles/Particle.h"
#include "ParticleSystems/Fuente.h"

using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;


PxMaterial*				gMaterial	= NULL;

PxPvd*                  gPvd        = NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene      = NULL;
ContactReportCallback gContactReportCallback;

Particle* suelo;
Particle* diana;

std::list<Particle*>  particles;

enum ProyectilType {
	PISTOL,
	ARTILLERY,
	FIREBALL,
	LASER
};

ProyectilType pType = PISTOL;



// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	suelo = new Particle({ 0, 0, 0 }, CreateShape(physx::PxBoxGeometry(300, 1, 300)));
	suelo->setColor({ 0.5, 0.5, 0, 1 });
	diana = new Particle({ -10, 30, -10 }, CreateShape(physx::PxSphereGeometry(10)));
	diana->setColor({ 1, 0, 0, 1 });
	//fuente = new Fuente({ 0, 0, 0 }, { 5, 30, 5 }, { 0, -9.8, 0 });
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	gScene->fetchResults(true);

	for (auto p : particles)
		p->integrate(t);

	for (auto p = particles.begin(); p != particles.end(); ) {
		if ((*p)->getPos().y < 0) {
			auto aux = p;
			p++;
			delete* aux;
			particles.erase(aux);
		}
		else p++;		
	}
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	
	gFoundation->release();
}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	switch (toupper(key))
	{
	case 'Q': {
		Vector3 eye = GetCamera()->getEye();
		Vector3 dir = GetCamera()->getDir();
		Particle* p = new Particle(eye);
		particles.push_back(p);
		switch (pType)
			{
			case PISTOL:
				p->setMass(0.2f);
				p->setVel(dir * 35);
				p->setAcc({ 0, -1.0f, 0 });
				p->setD(0.99f);
				p->setColor({ 0.2, 0.2, 0.2, 1});
				break;
			case ARTILLERY:
				p->setMass(200.0f);
				p->setVel(dir * 30);
				p->setAcc({ 0, -20.0f, 0 });
				p->setD(0.99f);
				p->setColor({ 0, 0, 0, 1 });
				break;
			case FIREBALL:
				p->setMass(1.0f);
				p->setVel(dir * 10);
				p->setAcc({ 0, 0.6f, 0 });
				p->setD(0.9f);
				p->setColor({ 1, 0, 0, 1 });
				break;
			case LASER:
				p->setMass(0.1f);
				p->setVel(dir * 100);
				p->setD(0.99f);
				p->setColor({ 0, 0, 1, 1 });
				break;
			}
		break;
		}	
	case 'Z':
		pType = PISTOL;
		break;
	case 'X':
		pType = ARTILLERY;
		break;
	case 'C':
		pType = FIREBALL;
		break;
	case 'V':
		pType = LASER;
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}


int main(int, const char*const*)
{
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	for (auto p : particles)
		delete p;

	delete suelo;
	delete diana;

	return 0;
}