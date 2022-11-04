#pragma once

#include <map>
#include "ForceGenerator.h"

typedef std::pair<ForceGenerator*, Particle*> FRPair;

class ParticleForzeRegistry : public std::multimap<ForceGenerator*, Particle*> {
public:
	void updteForces(double duration) {
		for (auto it = begin(); it != end(); it++) {
			it->first->updateForce(it->second, duration);
		}
	}

	void addRegistry(ForceGenerator* fg, Particle* p) {
		insert({ fg, p });
	}

	void deleteParticleRegistry(Particle* p) {
	}
};
