#pragma once

#include <list>
#include <PxPhysicsAPI.h>

#include "../core.hpp"

using namespace physx;

class PxForceGenerator
{
public:

	virtual ~PxForceGenerator() = default;

	virtual void updateForce(PxRigidDynamic* particle, double dt) = 0;
	double t = -1e10;
};

