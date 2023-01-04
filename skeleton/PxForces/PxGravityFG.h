#pragma once

#include "PxForceGenerator.h"

class PxGravityFG : public PxForceGenerator
{
public:
	PxGravityFG(const Vector3& g);

	virtual void updateForce(PxParticle* particle, double dt) override;

	inline void setGravity(const Vector3& g) { gravity = g; }

protected:
	Vector3 gravity;

};


