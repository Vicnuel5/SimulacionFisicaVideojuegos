#pragma once

#include "PxPickableParticle.h"

class SmokeSystem;

class Sarten : public PxPickableParticle
{
	physx::PxVec3 tamAceite;
	
	SmokeSystem* smokeSystem;

public:
	Sarten(physx::PxPhysics* physx, physx::PxTransform& pose, SmokeSystem* smokeSystem);
	~Sarten() = default;

	virtual void integrate(float dt) override;

	void echarAceite();
	void quemarAceite();
};



