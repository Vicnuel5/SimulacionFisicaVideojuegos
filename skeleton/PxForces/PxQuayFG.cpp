#include "PxQuayFG.h"

PxQuayFG::PxQuayFG(PxParticle* p, double longReposo, double k) :
	myParticle(p), longReposo(longReposo), K(k)
{
}

void PxQuayFG::updateForce(PxParticle* particle, double t)
{
	Vector3 force = myParticle->particle->getGlobalPose().p - particle->particle->getGlobalPose().p;

	const float lenght = force.normalize();
	const float delta_x = lenght - longReposo;

	force *= delta_x * K;

	particle->particle->addForce(force);
}

void PxQuayFG::setK(double k)
{
	K = k;
}
