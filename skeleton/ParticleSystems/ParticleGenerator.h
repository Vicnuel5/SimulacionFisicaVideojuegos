#pragma once

#include "../core.hpp"

#include <list>
#include <random>

class Particle;

class ParticleGenerator {

public:
	ParticleGenerator();
	virtual ~ParticleGenerator();

	void integrate(double t);

protected:	
	std::mt19937 gen;

	std::list<Particle*> particles;
	std::list<ParticleGenerator*> particle_generators;

	virtual std::list<Particle*> generateParticles() {
		return  std::list<Particle*>();
	}

	virtual void p_Integrate(double t) = 0;
	virtual void p_Refresh() = 0;
	
};
