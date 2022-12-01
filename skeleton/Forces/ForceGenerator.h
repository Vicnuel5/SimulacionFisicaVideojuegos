#pragma once

#include "../Particles/Particle.h"
#include <list>
#include <random>

class ForceGenerator
{
public:

	virtual ~ForceGenerator() = default;

	virtual void updateForce(Particle* myParticle, double duration) = 0;
	std::string name;
	double t = -1e10;
};

