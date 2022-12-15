#include "PxGravityFG.h"

PxGravityFG::PxGravityFG(const Vector3& g) :
	gravity(g)
{
}

void PxGravityFG::updateForce(PxRigidDynamic* particle, double dt)
{
	if (fabs(particle->getInvMass()) < 1e-10)
		return;

	particle->addForce(gravity * particle->getMass());
}
