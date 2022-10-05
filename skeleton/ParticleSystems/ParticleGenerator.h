#pragma once

#include "../core.hpp"
#include "../RenderUtils.hpp"

#include <list>

class Particle;


class ParticleGenerator {

public:
	ParticleGenerator();
	virtual ~ParticleGenerator();

	virtual std::list<Particle*> generateParticles() {
		return  std::list<Particle*>();
	}

	void integrate(double t);

protected:	
	std::list<Particle*> particles;
	std::list<ParticleGenerator*> particle_generators;

	virtual void pIntegrate(double t) {};
	
	
};
