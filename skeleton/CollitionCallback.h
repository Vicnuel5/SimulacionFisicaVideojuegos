#pragma once

#include <PxPhysicsAPI.h>

#include <list>

#include "PxParticles/PxParticle.h"
#include "PxParticles/Sarten.h"
#include "PxParticles/Vitro.h"

#include "PxParticleSystems/OilSystem.h"
#include "PxParticleSystems/SmokeSystem.h"


class CollitionCallback : public physx::PxSimulationEventCallback
{
	Sarten* objSarten;
	Vitro* objVitro;
	
	physx::PxRigidDynamic* sarten;
	physx::PxRigidStatic* vitro;

	std::list<PxParticle*>* oilParticles;
	OilSystem* oilSysyem;

	std::list<PxParticle*>* smokeParticles;
	SmokeSystem* smokeSysyem;
	physx::PxRigidStatic* techoCampana;


public:

	CollitionCallback(Sarten* sarten, Vitro* vitro, OilSystem* oilSysyem, SmokeSystem* smokeSysyem, physx::PxRigidStatic* techoCampana) :
		objSarten(sarten), sarten(sarten->particle), objVitro(vitro), vitro(vitro->rigid),
		oilParticles(oilSysyem->getParticleList()), oilSysyem(oilSysyem),
		smokeParticles(smokeSysyem->getParticleList()), smokeSysyem(smokeSysyem), techoCampana(techoCampana) {};

	void onConstraintBreak(physx::PxConstraintInfo* /*constraints*/, physx::PxU32 /*count*/) override {  }
	void onWake(physx::PxActor** /*actors*/, physx::PxU32 /*count*/) override {  }
	void onSleep(physx::PxActor** /*actors*/, physx::PxU32 /*count*/) override {  }
	void onTrigger(physx::PxTriggerPair* /*pairs*/, physx::PxU32 /*count*/) override {  }
	void onAdvance(const physx::PxRigidBody* const* /*bodyBuffer*/, const physx::PxTransform* /*poseBuffer*/, const physx::PxU32 /*count*/) override { std::printf("onAdvance\n"); }

	void onContact(const physx::PxContactPairHeader& pairHeader, const physx::PxContactPair* pairs, physx::PxU32 nbPairs) override
	{
		PxRigidActor* actor1 = pairHeader.actors[0];
		PxRigidActor* actor2 = pairHeader.actors[1];

		if (actor2 == sarten) {
			for (auto it = (*oilParticles).begin(); it != (*oilParticles).end(); ) {
				if ((*it)->particle == actor1) {
					auto aux = it;
					it++;
					oilSysyem->desregisterParticle((*aux));
					objSarten->echarAceite();
					delete* aux;
					(*oilParticles).erase(aux);
				}
				else it++;
			}
		}

		if (actor2 == techoCampana) {
			for (auto it = (*smokeParticles).begin(); it != (*smokeParticles).end(); ) {
				if ((*it)->particle == actor1) {
					auto aux = it;
					it++;
					smokeSysyem->desregisterParticle((*aux));
					delete* aux;
					(*smokeParticles).erase(aux);
				}
				else it++;
			}
		}

		if (actor2 == vitro) {
			if (actor1 == sarten) {
				if (objVitro->turnOn())
					objSarten->quemarAceite();
			}
		}
	}
};

