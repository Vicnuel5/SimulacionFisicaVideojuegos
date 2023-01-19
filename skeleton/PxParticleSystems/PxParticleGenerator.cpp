#include "PxParticleGenerator.h"

#include "../PxParticles/PxParticle.h"

PxParticleGenerator::PxParticleGenerator(physx::PxPhysics* physx, physx::PxScene* scene) :
	physx(physx), scene(scene)
{
	std::random_device rd{};
	gen = std::mt19937(rd());
}

PxParticleGenerator::~PxParticleGenerator()
{
	for (auto p : particles)
		delete p;

	particles.clear();

	for (auto pg : particle_generators)
		delete pg;

	particle_generators.clear();


	for (auto fg : force_generators)
		delete fg;

	forces.clear();
}

void PxParticleGenerator::integrate(double t)
{
	forces.updteForces(t);

	for (auto p : particles)
		p->integrate(t);

	for (auto pg : particle_generators)
		pg->integrate(t);

	p_Integrate(t);
	p_Refresh();
}

void PxParticleGenerator::addForce(PxForceGenerator* fg) {
	force_generators.push_back(fg);
}

void PxParticleGenerator::desregisterParticle(PxParticle* particle)
{
	forces.deleteParticleRegistry(particle);
}

std::list<PxParticle*>* PxParticleGenerator::getParticleList()
{
	return &particles;
}


