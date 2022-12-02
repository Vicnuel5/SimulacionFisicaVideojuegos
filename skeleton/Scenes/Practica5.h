#pragma once

#include "Scene.h"

#include <PxPhysicsAPI.h>

class Practica5 : public Scene
{
	
public:
	Practica5(physx::PxPhysics* gPhysics, physx::PxScene* gScene) 
		: Scene(), myScene(gScene), myPhysics(gPhysics) {};
	~Practica5() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;
	virtual void s_keyPress(unsigned char key) override;

protected:
	physx::PxPhysics* myPhysics;
	physx::PxScene* myScene;
};

