#include "PxAbductFG.h"

PxAbductFG::PxAbductFG(Vector3 abductPos, float abductForce, float abductRange)
	: abductPos(abductPos), abductForce(abductForce), abductRange(abductRange), active(false)
{
}

void PxAbductFG::updateForce(PxParticle* particle, double dt)
{

	if (active) {
		if (fabs(particle->particle->getInvMass()) < 1e-10)
			return;

		Vector3 force = (particle->particle->getGlobalPose().p - abductPos);
		float dist = force.magnitude();
		if (dist <= abductRange) {

			force = force.getNormalized() * (1 - (dist / abductRange) * abductForce);
			particle->particle->addForce(force * particle->particle->getMass());
		}
	}
}

void PxAbductFG::Activate()
{
	active = !active;
}
