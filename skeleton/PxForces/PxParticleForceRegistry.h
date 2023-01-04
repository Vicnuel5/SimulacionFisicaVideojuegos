#pragma once

#include <map>
#include <vector>
#include "PxForceGenerator.h"

typedef std::pair<PxForceGenerator*, PxParticle*> PxFRPair;

class PxParticleForzeRegistry : public std::multimap<PxForceGenerator*, PxParticle*> {
public:
	void updteForces(double dt) {
		for (auto it = begin(); it != end(); it++) {
			it->first->updateForce(it->second, dt);
		}
	}

	void addRegistry(PxForceGenerator* f, PxParticle* p) {
		insert({ f, p });
	}

	void addRegistry(std::vector<PxForceGenerator*> f, PxParticle* p) {
		for (auto i : f) {
			insert({ i, p });
		}
	}

	void deleteParticleRegistry(PxParticle* p) {
		for (auto it = begin(); it != end(); ) {
			if (it->second == p) {
				auto aux = it;
				it++;
				erase(aux);
			}
			else it++;
		}
	}

	void deleteForceRegistry(PxForceGenerator* f) {
		for (auto it = begin(); it != end(); ) {
			if (it->first == f) {
				auto aux = it;
				it++;
				erase(aux);
			}
			else it++;
		}
	}
};

