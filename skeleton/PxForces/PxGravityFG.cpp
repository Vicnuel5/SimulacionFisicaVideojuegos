#include "PxGravityFG.h"

PxGravityFG::PxGravityFG(const Vector3& g) :
	gravity(g)
{
}

void PxGravityFG::updateForce(PxParticle* particle, double dt)
{
	if (fabs(particle->particle->getInvMass()) < 1e-10)
		return;

	particle->particle->addForce(gravity * particle->particle->getMass());
}
