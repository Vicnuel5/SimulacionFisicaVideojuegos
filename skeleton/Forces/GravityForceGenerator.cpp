#include "GravityForceGenerator.h"

GravityForceGenerator::GravityForceGenerator(const Vector3& g) 
	: gravity(g)
{
}

void GravityForceGenerator::updateForce(Particle* myParticle, double t)
{
	if (fabs(myParticle->getInvMass()) < 1e-10)
		return;

	myParticle->addForce(gravity * myParticle->getMass());
}
