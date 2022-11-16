#include "ExplosionForceGenerator.h"

#include <iostream>

ExplosionForceGenerator::ExplosionForceGenerator(const Vector3& pos, double area, double duration) :
	expPos(pos), radius(area), duration(duration)
{
	t = duration;
}

void ExplosionForceGenerator::updateForce(Particle* particle, double dt) {

	if (t >= duration) {
		return;
	}
	t += dt;

	if (fabs(particle->getInvMass()) < 1e-10)
		return;

	if ((particle->getPos() - expPos).magnitudeSquared() > radius * radius) {
		return;
	}

	double K = 8000, n = 1;
	particle->addForce((K / (radius * radius)) * (particle->getPos() - expPos) * pow(2.71828, -((t / 1000.0) / n)));
}

void ExplosionForceGenerator::resetExplsion() {
	if (t >= duration)
		t = 0;
}