#pragma once

#include <list>


#include "../core.hpp"
#include "../PxParticles/PxParticle.h"



class PxForceGenerator
{
public:

	virtual ~PxForceGenerator() = default;

	virtual void updateForce(PxParticle* particle, double dt) = 0;
	double t = -1e10;
};

