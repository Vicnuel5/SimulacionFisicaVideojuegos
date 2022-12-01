#pragma once

#include "ForceGenerator.h"

class ParticleBungeeForceGenerator : public ForceGenerator
{
public:
	ParticleBungeeForceGenerator(Particle* other, double restLengh, double k);
	~ParticleBungeeForceGenerator();

	virtual void updateForce(Particle* myParticle, double t);

protected:
	double K;
	double restLengh;
	Particle* other;
};

