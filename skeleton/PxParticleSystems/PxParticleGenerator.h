#pragma once

#include "../core.hpp"
#include "../PxForces/PxParticleForceRegistry.h"

using namespace physx;

#include <list>
#include <vector>
#include <random>

class PxParticle;

class PxParticleGenerator {

public:
	PxParticleGenerator(physx::PxPhysics* physx, physx::PxScene* scene);
	virtual ~PxParticleGenerator();

	void integrate(double t);

	void addForce(PxForceGenerator* fg);

	void desregisterParticle(PxParticle* particle);
	std::list<PxParticle*>* getParticleList();

protected:
	physx::PxPhysics* physx;
	physx::PxScene* scene;

	std::mt19937 gen;

	std::list<PxParticle*> particles;
	std::list<PxParticleGenerator*> particle_generators;

	PxParticleForzeRegistry forces;
	std::vector<PxForceGenerator*> force_generators;

	virtual std::list<PxParticle*> generateParticles() {
		return std::list<PxParticle*>();
	}

	virtual void p_Integrate(double t) = 0;
	virtual void p_Refresh() = 0;
};






