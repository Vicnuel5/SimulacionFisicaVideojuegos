#include "ExplosionForceGenerator.h"

#include <iostream>

ExplosionForceGenerator::ExplosionForceGenerator(const Vector3& pos) :
	expPos(pos), vExp(0.343), K(10000), n(3000), active(false)
{
	t = 0;
}

ExplosionForceGenerator::ExplosionForceGenerator(const Vector3& pos, double vExp, double K, double n) :
	expPos(pos), vExp(vExp), K(K), n(n), active(false)
{
	t = 0;
}

void ExplosionForceGenerator::updateForce(Particle* particle, double dt) {

	if (!active) {
		return;
	}

	t += dt;
	double r = vExp * t;

	if (fabs(particle->getInvMass()) < 1e-10)
		return;

	double sqrDist = (particle->getPos() - expPos).magnitudeSquared();
	if (sqrDist > r * r) {
		return;
	}

	particle->addForce((K / sqrDist) * (particle->getPos() - expPos) * exp(-t/n));
}

void ExplosionForceGenerator::resetExplsion() {
	active = true;
}