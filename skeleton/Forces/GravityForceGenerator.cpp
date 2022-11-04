#include "GravityForceGenerator.h"

GravityForceGenerator::GravityForceGenerator(const Vector3& g) 
	: gravity(g)
{
}

void GravityForceGenerator::updateForce(Particle* particle, double t)
{
	if (fabs(particle->getMass()) < 1e-10)
		return;

	particle->addForce(gravity);
}
