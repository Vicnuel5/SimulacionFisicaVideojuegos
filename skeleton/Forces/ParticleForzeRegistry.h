#pragma once

#include <map>
#include <vector>
#include "ForceGenerator.h"

typedef std::pair<ForceGenerator*, Particle*> FRPair;

class ParticleForzeRegistry : public std::multimap<ForceGenerator*, Particle*> {
public:
	void updteForces(double duration) {
		for (auto it = begin(); it != end(); it++) {
			it->first->updateForce(it->second, duration);
		}
	}

	void addRegistry(ForceGenerator* gravity, Particle* p) {
		insert({ gravity, p });
	}

	void addRegistry(std::vector<ForceGenerator*> gravity, Particle* p) {
		for (auto i : gravity) {
			insert({ i, p });
		}	
	}
	 
	void deleteParticleRegistry(Particle* p) {
		for (auto it = begin(); it != end(); ) {
			if (it->second == p) {
				auto aux = it;
				it++;
				erase(aux);
			}
			else it++;
		}
	}

	void deleteForceRegistry(ForceGenerator* gravity) {
		for (auto it = begin(); it != end(); ) {
			if (it->first == gravity) {
				auto aux = it;
				it++;
				erase(aux);
			}
			else it++;
		}
	}
};
