#include "ParticleBungeeForceGenerator.h"

ParticleBungeeForceGenerator::ParticleBungeeForceGenerator(Particle* other, double restLengh, double k) :
	other(other), restLengh(restLengh), K(k)
{
}

ParticleBungeeForceGenerator::~ParticleBungeeForceGenerator()
{
}

void ParticleBungeeForceGenerator::updateForce(Particle* myParticle, double t)
{
	Vector3 f = myParticle->getPos();
	f -= other->getPos();

	float lenght = f.normalize();
	lenght = lenght - restLengh;
	if (lenght <= 0.0f)
		return;

	f *= -(lenght * K);
	myParticle->addForce(f);
}
