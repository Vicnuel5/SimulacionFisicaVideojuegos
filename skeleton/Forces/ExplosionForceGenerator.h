#pragma once

#include "ForceGenerator.h"
#include "../core.hpp"

class ExplosionForceGenerator : public ForceGenerator
{

public:
	ExplosionForceGenerator(const Vector3& pos);
	ExplosionForceGenerator(const Vector3& pos, double vExp, double K, double n);
	virtual ~ExplosionForceGenerator() = default;

	virtual void updateForce(Particle* particle, double t);

	void resetExplsion();

protected:
	Vector3 expPos;
	double vExp;
	double K;
	double n;
	float active;
};