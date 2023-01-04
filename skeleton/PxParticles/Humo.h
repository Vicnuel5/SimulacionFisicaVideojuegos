#pragma once

#include "PxPickableParticle.h"

class ParticleHumo : public PxParticle
{

public:
	ParticleHumo(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~ParticleHumo() = default;

	float angle;
	float angleIncr;
	int cont;
	int maxTime;
	float radius;

	float flowTime;
	float flowMaxTime;
	float flowForce;
};

