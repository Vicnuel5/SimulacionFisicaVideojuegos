#pragma once

#include <map>
#include <vector>
#include "PxForceGenerator.h"

typedef std::pair<PxForceGenerator*, PxRigidDynamic*> PxFRPair;

class PxParticleForzeRegistry : public std::multimap<PxForceGenerator*, PxRigidDynamic*> {
public:
	void updteForces(double dt) {
		for (auto it = begin(); it != end(); it++) {
			it->first->updateForce(it->second, dt);
		}
	}

	void addRegistry(PxForceGenerator* f, PxRigidDynamic* p) {
		insert({ f, p });
	}

	void addRegistry(std::vector<PxForceGenerator*> f, PxRigidDynamic* p) {
		for (auto i : f) {
			insert({ i, p });
		}
	}

	void deleteParticleRegistry(PxRigidDynamic* p) {
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

