#pragma once

#include "PxParticleGenerator.h"

#include "../PxParticles/PxParticle.h"


class PxGravityFG;
class Sarten;

class OilSystem : public PxParticleGenerator
{
	double cont;
	const double SPAWN_TIME = 0.001;
	bool activated;

public:
	OilSystem(physx::PxPhysics* physx, physx::PxScene* scene);
	~OilSystem() = default;

	void Activate(Vector3 std_dev_pos);

protected:
	Vector3 std_dev_pos;

	std::normal_distribution<float> dPos{ 0, 0.1 };

	void p_Integrate(double t) override;
	void p_Refresh() override {};
};





	


