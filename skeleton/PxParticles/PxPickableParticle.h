#pragma once

#include "PxParticle.h"


class PxPickableParticle : public PxParticle
{

public:
	PxPickableParticle(physx::PxPhysics* physx, physx::PxTransform& pose) :
		PxParticle(physx, pose) {};
	virtual ~PxPickableParticle() = default;

	virtual bool canPick() override { return true; }
};

