#pragma once

#include "Scene.h"
#include "../PxForces/PxParticleForceRegistry.h"

#include <PxPhysicsAPI.h>

#include <list>

#define THROW_FORCE 50000

class PxParticle;
class PxRigid;
class PxRigidGroup;

class Vitro;
class CampanaExtractora;

class PxGravityFG;
class PxQuayFG;

class OilSystem;
class SmokeSystem;

class ProyectoFinal : public Scene
{

public:
	ProyectoFinal(physx::PxPhysics* gPhysics, physx::PxScene* gScene)
		: Scene(), myScene(gScene), myPhysics(gPhysics) {};
	~ProyectoFinal() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;
	virtual void s_keyPress(unsigned char key) override;

	void init_actors();
	void mouse_click();
	void pick_object();
	void pick_object2();
	void throw_object();

protected:
	physx::PxPhysics* myPhysics;
	physx::PxScene* myScene;

	PxParticleForzeRegistry forces;
	PxGravityFG* gravity;
	std::list<PxQuayFG*> slink;

	std::list<PxParticle*> particles;
	std::list<PxRigid*> rigids;
	std::list<PxRigidGroup*> gRigids;

	PxParticle* pickedObject;

	Vitro* vitro;
	CampanaExtractora* campanaExtractora;

	OilSystem* oilSys;
	SmokeSystem* smokeSys;
};

