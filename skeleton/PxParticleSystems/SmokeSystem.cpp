#include "SmokeSystem.h"

#include "../PxParticles/Humo.h"

#include "../PxForces/PxFlowFG.h"
#include "../PxForces/PxRotationFG.h"
#include "../PxForces/PxAbductFG.h"

SmokeSystem::SmokeSystem(physx::PxPhysics* physx, physx::PxScene* scene, Vector3 campanaExtractora) :
	PxParticleGenerator(physx, scene), activated(false), cont(0), std_dev_pos(PxVec3())
{
	abductForce = new PxAbductFG(campanaExtractora, 30, 25);
	force_generators.push_back(abductForce);
	force_generators.push_back(new PxFlowFG());
	force_generators.push_back(new PxRotationFG());
}


void SmokeSystem::ActivateCampana()
{
	abductForce->Activate();
}

void SmokeSystem::Activate(physx::PxVec3 pos)
{
	std_dev_pos = pos;
	activated = !activated;
}


void SmokeSystem::p_Integrate(double t)
{

	if (activated) {
		cont += t;
		activated = false;

		if (cont >= SPAWN_TIME) {

			ParticleHumo* p = new ParticleHumo(physx, PxTransform(std_dev_pos
				+ PxVec3(dPos(gen), 1.5, dPos(gen))));
			scene->addActor(*p->particle);


			p->maxTime = 0.1;
			p->cont = p->maxTime;
			p->radius = 20;
			p->angle = intAngleD(gen);
			p->angleIncr = 4;

			p->flowMaxTime = 3;
			p->flowForce = 15;


			particles.push_back(p);
			forces.addRegistry(force_generators, p);

			cont = 0;
		}
	}
}

void SmokeSystem::p_Refresh()
{
}







