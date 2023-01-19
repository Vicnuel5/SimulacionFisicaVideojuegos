#pragma once

#include "PxParticleGenerator.h"


class PxAbductFG;


class SmokeSystem : public PxParticleGenerator
{
	double cont;
	const double SPAWN_TIME = 0.1;
	bool activated;

	

public:
	SmokeSystem(physx::PxPhysics* physx, physx::PxScene* scene, Vector3 campanaExtractora);
	virtual ~SmokeSystem() = default;

	void ActivateCampana();
	void Activate(physx::PxVec3 pos);


protected:
	Vector3 std_dev_pos;

	std::normal_distribution<float> dPos{ 0, 1.5 };
	std::uniform_real_distribution<float> intAngleD{ 0, 360 };

	void p_Integrate(double t) override;
	void p_Refresh() override {};

	PxAbductFG* abductForce;
};










