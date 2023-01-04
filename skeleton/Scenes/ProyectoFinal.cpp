#include "ProyectoFinal.h"

#include "../RenderUtils.hpp"

#include "../PxParticles/Puerta.h"
#include "../PxParticles/AllRigids.h"
#include "../PxParticles/Sarten.h"
#include "../PxParticles/Aceite.h"
#include "../PxParticles/Campana.h"
#include "../PxParticles/Comida.h"

#include "../PxForces/PxGravityFG.h"
#include "../PxForces/PxAnchoredSpringFG.h"
#include "../PxForces/PxQuayFG.h"

#include "../PxParticleSystems/OilSystem.h"
#include "../PxParticleSystems/SmokeSystem.h"


#include "../CollitionCallback.h"

#include <iostream>
using namespace std;

using namespace physx;

void ProyectoFinal::s_init()
{
	pickedObject = nullptr;

	PxVec4 colorPared = PxVec4(0.6f, 0.6f, 0.7f, 1);

	rigids.push_back(new Suelo(myPhysics, PxTransform({ -10, -0.5, 0 }), 
		PxVec3(45, 1, 25), PxVec4(0.7f,0.7f,0.95f,1)));
	rigids.push_back(new Columna(myPhysics, PxTransform({ -45, 38.5, -15 }),
		PxVec3(10,40,10), PxVec4(0.85f, 0.85f, 0.85f, 1)));
	rigids.push_back(new Tarima(myPhysics, PxTransform({ -9, 17, -15 }), 
		PxVec3(26, 0.5, 10), PxVec4(0.2f, 0.2f, 0.2f, 1)));
	rigids.push_back(new ParedEO(myPhysics, PxTransform({ 35.5, 38.5, 0 }),
		PxVec3(0.5, 40, 25), colorPared));
	rigids.push_back(new ParedEO(myPhysics, PxTransform({ -55.5, 38.5, 0 }),
		PxVec3(0.5, 40, 25), colorPared));
	rigids.push_back(new ParedN(myPhysics, PxTransform({ -10, 38.5, -25 }),
		PxVec3(45, 40, 1), colorPared));
	rigids.push_back(new PataTarima(myPhysics, PxTransform({ 15, 6.5, -15 }),
		PxVec3(1.25, 10, 10), colorPared));
	vitro = new Vitro(myPhysics, PxTransform({ -3.5, 17.5, -14 }),
		PxVec3(5, 0.25, 7), PxVec4(0, 0, 0, 1));
	rigids.push_back(vitro);

	gRigids.push_back(new Nevera(myPhysics, PxTransform({ 26, 20.5, -15 }), PxVec4(1,0,0,1)));
	gRigids.push_back(new Cajon(myPhysics, PxTransform({ -10.25, 7, -13.5 }), PxVec4(1, 0, 0, 1)));
	gRigids.push_back(new Cajon(myPhysics, PxTransform({ -26.25, 7, -13.5 }), PxVec4(1, 0, 0, 1)));
	gRigids.push_back(new Cajon(myPhysics, PxTransform({ 5.75, 7, -13.5 }), PxVec4(1, 0, 0, 1)));
	smokeSys = new SmokeSystem(myPhysics, myScene, Vector3(-5, 55, -15));
	campanaExtractora = new CampanaExtractora(myPhysics, PxTransform({ -5, 45, -15 }), PxVec4(1, 0, 0, 1), smokeSys);
	gRigids.push_back(campanaExtractora);

	particles.push_back(new PuertaNevera(myPhysics, (PxTransform({ 26, 16, -7 }))));
	particles.push_back(new PuertaNevera2(myPhysics, (PxTransform({ 26, 35.5, -7 }))));
	particles.push_back(new PuertaCajon(myPhysics, (PxTransform({ -10.25, 7, -5.75 }))));
	particles.push_back(new PuertaCajon(myPhysics, (PxTransform({ -26.25, 7, -5.75 }))));
	particles.push_back(new PuertaCajon(myPhysics, (PxTransform({ 5.75, 7, -5.75 }))));

	particles.push_back(new Cebolla(myPhysics, (PxTransform({ 0, 18, -15 }))));
	particles.push_back(new Tomate(myPhysics, (PxTransform({ 0, 18, -15 }))));
	particles.push_back(new Tortilla(myPhysics, (PxTransform({ 0, 18, -10 }))));
	particles.push_back(new Agua(myPhysics, (PxTransform({ 5, 18, -10 }))));

	
	Sarten* sarten = new Sarten(myPhysics, (PxTransform({ -9, 18, -15 })), smokeSys);
	particles.push_back(sarten);
	oilSys = new OilSystem(myPhysics, myScene);
	particles.push_back(new Aceite(myPhysics, PxTransform({ -30, 24, -20 }), oilSys));
	particles.push_back(new Aceite(myPhysics, PxTransform({ -30, 24, -17 }), oilSys));

	

	CollitionCallback* callback = new CollitionCallback(sarten, vitro, oilSys, smokeSys, (*(--campanaExtractora->rigids.end()))->rigid);
	myScene->setSimulationEventCallback(callback);


	myScene->setGravity({ 0, 0, 0 });
	gravity = new PxGravityFG(PxVec3(0, -98, 0));
	for (auto p : particles)
		forces.addRegistry(gravity, p);

	//------------

	double K = 200;
	double lon = 1.5;
	PxVec3 pos = PxVec3(-53, 35, 16);

	PxParticle* p = new Cebolla(myPhysics, PxTransform({ pos.x, pos.y - 2, pos.z }));
	p->particle->setMass(1);
	p->particle->setLinearDamping(0.8);

	forces.addRegistry(gravity, p);

	auto f = new PxAnchoredSpringFG(new SoporteComida(myPhysics, PxTransform(pos)), lon, K);
	forces.addRegistry(f, p);
	slink.push_back(f);
	particles.push_back(p);

	int n = 4;
	pos.y -= 4;
	for (int i = 0; i < n; i++) {
		PxParticle* p2 = new Cebolla(myPhysics, (PxTransform(pos)));
		p2->particle->setMass(1);
		p2->particle->setLinearDamping(0.8);
		pos.y -= 2;

		forces.addRegistry(gravity, p2);

		auto muelle = new PxQuayFG(p, lon, K);
		forces.addRegistry(muelle, p2);
		slink.push_back(muelle);
		muelle = new PxQuayFG(p2, lon, K);
		forces.addRegistry(muelle, p);
		slink.push_back(muelle);
		particles.push_back(p2);

		p = p2;
	}

	//------------

	K = 50;
	lon = 1.5;
	pos = PxVec3(-53, 35, 4);

	p = new Tomate(myPhysics, PxTransform({ pos.x, pos.y - 4, pos.z }));
	p->particle->setMass(1);
	p->particle->setLinearDamping(0.8);

	forces.addRegistry(gravity, p);

	f = new PxAnchoredSpringFG(new SoporteComida(myPhysics, PxTransform(pos)), lon, K);
	forces.addRegistry(f, p);
	slink.push_back(f);
	particles.push_back(p);

	n = 2;
	pos.y -= 8;
	for (int i = 0; i < n; i++) {
		PxParticle* p2 = new Tomate(myPhysics, (PxTransform(pos)));
		p2->particle->setMass(1);
		p2->particle->setLinearDamping(0.8);
		pos.y -= 4;

		forces.addRegistry(gravity, p2);

		auto muelle = new PxQuayFG(p, lon, K);
		forces.addRegistry(muelle, p2);
		slink.push_back(muelle);
		muelle = new PxQuayFG(p2, lon, K);
		forces.addRegistry(muelle, p);
		slink.push_back(muelle);
		particles.push_back(p2);

		p = p2;
	}

	//---------------





	init_actors();
}

void ProyectoFinal::init_actors()
{
	for (auto p : particles)
		myScene->addActor(*p->particle);

	for (auto r : rigids)
		myScene->addActor(*r->rigid);

	for (auto gr : gRigids) 
		for (auto r : gr->rigids) 
			myScene->addActor(*r->rigid);

}

void ProyectoFinal::s_clean()
{

	for (auto p : particles)
		delete p;

	for (auto r : rigids)
		delete r;

	for (auto gr : gRigids)
		delete gr;

	delete gravity;

	for (auto s : slink)
		delete s;


	delete oilSys;
	delete smokeSys;
}

void ProyectoFinal::s_integrate(float t)
{
	forces.updteForces(t);
 
	for (auto p : particles)
		p->integrate(t);

	mouse_click();
}

void ProyectoFinal::s_keyPress(unsigned char key)
{
	switch (key)
	{
		case 'E': {
			if (pickedObject != nullptr && pickedObject->canInteract())
				pickedObject->interact();
			break;
		}
		case 'Z': {
			vitro->turnOnOff();
			break;
		}	
		case 'X': {
			campanaExtractora->turnOnOff();
			break;
		}
	}
}



void ProyectoFinal::mouse_click()
{
	auto c = GetCamera();
	if (c->leftClick()) {
		//cout << "ClickIz\n";
		pick_object2();
	}
	if (c->rightClick()) {
		//cout << "ClickDr\n";
		throw_object();
		
	}
	if (c->middleClick()) {
		//cout << "ClickMd\n";
		pick_object();
	}
}

void ProyectoFinal::pick_object()
{
	if (pickedObject == nullptr) {
		auto c = GetCamera();
		PxVec3 hitbox_dist = c->getEye() + c->getDir().getNormalized() * ITEM_DIST;
		float bestDist = 10000000;
		PxVec3 cameraPosition = c->getTransform().p;
		for (auto p : particles) {
			if (p->canPick() && (p->particle->getGlobalPose().p - hitbox_dist).magnitude() < PICK_RANGE) {
				float dist = (p->particle->getGlobalPose().p - cameraPosition).magnitude();
				if (dist < bestDist) {
					bestDist = dist;
					pickedObject = p;
				}
			}
		}
		if (pickedObject != nullptr) {
			pickedObject->setPick(true);
		}	
	}
	else {
		pickedObject->setPick(false);
		pickedObject = nullptr;
	}
}

void ProyectoFinal::pick_object2()
{
	if (pickedObject == nullptr) {
		auto c = GetCamera();
		PxVec3 hitbox_dist = c->getEye() + c->getDir().getNormalized() * ITEM_DIST;
		float bestDist = PICK_RANGE;
		for (auto p : particles) {
			if (p->canPick()) {
				float dist = (p->particle->getGlobalPose().p - hitbox_dist).magnitude();
				if (dist < PICK_RANGE) {
					bestDist = dist;
					pickedObject = p;
				}
			}
		}
		if (pickedObject != nullptr) {
			pickedObject->setPick(true);
		}
	}
	else {
		pickedObject->setPick(false);
		pickedObject = nullptr;
	}
}

void ProyectoFinal::throw_object()
{
	if (pickedObject != nullptr) {

		pickedObject->setPick(false);
		pickedObject->particle
			->addForce((GetCamera()->getDir().getNormalized()) * THROW_FORCE);
		pickedObject = nullptr;
	}
}




