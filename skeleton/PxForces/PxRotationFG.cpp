#include "PxRotationFG.h"

#include <math.h>       
#define PI 3.14159265f

#include "../PxParticles/Humo.h"

PxRotationFG::PxRotationFG()
{
}

void PxRotationFG::updateForce(PxParticle* particle, double dt)
{
	if (fabs(particle->particle->getInvMass()) < 1e-10)
		return;

	ParticleHumo* humo = (ParticleHumo*) particle;

	if (humo->cont >= humo->maxTime) {
		humo->cont = 0;
		
		Vector3 newForce = Vector3(cos(humo->angle * PI / 180.0f) * humo->radius, 
			sin(humo->angle * PI / 180.0f) * humo->radius, 0);
		humo->angle = humo->angle + humo->angleIncr;

		particle->particle->addForce(newForce * particle->particle->getMass());
	}
	else humo->cont += dt;
	
}
