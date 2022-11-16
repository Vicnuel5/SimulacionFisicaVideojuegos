#include "ParticleGenerator.h"

#include "../Particles/Particle.h"

ParticleGenerator::ParticleGenerator() 
{
	std::random_device rd{};
	gen = std::mt19937(rd());
}

ParticleGenerator::~ParticleGenerator()
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

void ParticleGenerator::integrate(double t)
{
	forces.updteForces(0);

	for (auto p : particles)
		p->integrate(t);

	for (auto pg : particle_generators)
		pg->integrate(t);

	p_Integrate(t);
	p_Refresh();
}

void ParticleGenerator::addForce(ForceGenerator* fg) {
	force_generators.push_back(fg);
}


