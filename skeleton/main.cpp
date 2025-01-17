#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>
#include <list>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "Scenes/ScenesInclude.h"

#define CAMERA_Y 15

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

Scene* scene;
bool lock = false;


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
	sceneDesc.gravity = PxVec3(0.0f, -98.0f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	
	scene = new ProyectoFinal(gPhysics, gScene);
	lock = true;
	//scene = new Practica1();
	scene->s_init();	
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	gScene->fetchResults(true);

	scene->s_integrate(t);
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

	scene->s_clean();
	delete scene;
}

void createScene(Scene* newScene) {
	
	scene->s_clean();
	delete scene;
	scene = newScene;
	scene->s_init();
}

void changeScene(unsigned char n) {

	if (!lock) {
		switch (n)
		{
			//case '1': createScene(new Practica1()); break;
			case '2': createScene(new Practica2_1()); break;
			case '3': createScene(new Practica2_2()); break;
			case '4': createScene(new Practica2_3()); break;
			case '5': createScene(new Practica3()); break;
			case '6': createScene(new Practica3_2()); break;
			case '7': createScene(new Practica3_3()); break;
			case '8': createScene(new Practica3_4()); break;
			case '9': createScene(new Practica4()); break;
			case '0': createScene(new Practica4_2()); break;
			case '1': createScene(new Practica4_3()); break;
		}
	}
}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	scene->s_keyPress(toupper(key));
	changeScene(key);
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

	return 0;
}