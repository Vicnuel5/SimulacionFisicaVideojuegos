#pragma once

#include "ForceGenerator.h"
#include "../core.hpp"

class ExplosionForceGenerator : public ForceGenerator
{

public:
	ExplosionForceGenerator(const Vector3& pos, double area, double duration);
	virtual ~ExplosionForceGenerator() = default;

	virtual void updateForce(Particle* particle, double t);

	void resetExplsion();

protected:
	Vector3 expPos;
	double radius;
	double duration;
	double n;
};