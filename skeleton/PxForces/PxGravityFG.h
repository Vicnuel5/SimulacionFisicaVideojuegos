#pragma once

#include "PxForceGenerator.h"


class PxGravityFG : public PxForceGenerator
{
public:
	PxGravityFG(const Vector3& g);

	virtual void updateForce(PxRigidDynamic* particle, double dt);

	inline void setGravity(const Vector3& g) { gravity = g; }

protected:
	Vector3 gravity;

};

