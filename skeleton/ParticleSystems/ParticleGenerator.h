#pragma once

#include "../core.hpp"
#include "../Forces/ParticleForzeRegistry.h"


#include <list>
#include <vector>
#include <random>

class Particle;

class ParticleGenerator {

public:
	ParticleGenerator();
	virtual ~ParticleGenerator();

	void integrate(double t);

	void addForce(ForceGenerator* fg);

protected:	
	std::mt19937 gen;

	std::list<Particle*> particles;
	std::list<ParticleGenerator*> particle_generators;

	ParticleForzeRegistry forces;
	std::vector<ForceGenerator*> force_generators;

	virtual std::list<Particle*> generateParticles() {
		return std::list<Particle*>();
	}

	virtual void p_Integrate(double t) = 0;
	virtual void p_Refresh() = 0;
};
