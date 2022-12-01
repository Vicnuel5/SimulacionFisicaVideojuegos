#include "QuayFoceGenerator.h"

QuayFoceGenerator::QuayFoceGenerator(Particle* p, double longReposo, double k) :
	myParticle(p), longReposo(longReposo), K(k)
{
}

void QuayFoceGenerator::updateForce(Particle* particle, double t)
{
	Vector3 force = myParticle->getPos() - particle->getPos();
	
	const float lenght = force.normalize();
	const float delta_x = lenght - longReposo;
	
	force *= delta_x * K;

	particle->addForce(force);
}

void QuayFoceGenerator::setK(double k)
{
	K = k;
}
