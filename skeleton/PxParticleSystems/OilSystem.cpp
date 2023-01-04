#include "OilSystem.h"

#include "../PxParticles/Aceite.h"
#include "../PxParticles/Sarten.h"

#include "../PxForces/PxGravityFG.h"

OilSystem::OilSystem(physx::PxPhysics* physx, physx::PxScene* scene) :
	PxParticleGenerator(physx, scene), activated(false), cont(0), std_dev_pos(PxVec3())
{
	force_generators.push_back(new PxGravityFG(PxVec3(0, -98, 0)));
}

void OilSystem::Activate(Vector3 pos)
{
	activated = true;
	std_dev_pos = pos;
}

void OilSystem::AceiteEnSarten(physx::PxRigidDynamic* particulaAceite)
{
	forces.deleteParticleRegistry(particulaAceite);
}

void OilSystem::p_Integrate(double t)
{

	if (activated) {
		cont += t;
		activated = false;

		if (cont >= SPAWN_TIME) {

			PxParticle* p = new ParticleAceite(physx, PxTransform(std_dev_pos 
				+ PxVec3(dPos(gen), 0, dPos(gen))));
			scene->addActor(*p->particle);

			
			particles.push_back(p);
			forces.addRegistry(force_generators, p->particle);

			cont = 0;
		}
	}
}

void OilSystem::p_Refresh()
{
	//for (auto it = particles.begin(); it != particles.end(); ) {
	//	if ((*it)->getPos().y < diePos) {
	//		auto aux = it;
	//		it++;
	//		forces.deleteParticleRegistry(*aux);
	//		delete* aux;
	//		particles.erase(aux);
	//	}
	//	else it++;
	//}
}







