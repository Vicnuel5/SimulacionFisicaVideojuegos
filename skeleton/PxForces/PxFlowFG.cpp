#include "PxFlowFG.h"
#include "../PxParticles/Humo.h"



PxFlowFG::PxFlowFG()
{
}

void PxFlowFG::updateForce(PxParticle* particle, double dt)
{
	

	if (fabs(particle->particle->getInvMass()) < 1e-10)
		return;

	ParticleHumo* humo = (ParticleHumo*)particle;

	if (humo->flowTime < humo->flowMaxTime) {

		Vector3 force = Vector3(0, 
			humo->flowForce * (1 - (humo->flowTime / humo->flowMaxTime)), 0);

		humo->flowTime += dt;

		particle->particle->addForce(force * particle->particle->getMass());
	}



	
}
