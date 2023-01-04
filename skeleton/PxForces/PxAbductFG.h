#pragma once

#include "PxForceGenerator.h"

static bool aaaa;

class PxAbductFG : public PxForceGenerator
{

	Vector3 abductPos;
	float abductForce;
	float abductRange;

	bool active;

	

public:
	PxAbductFG(Vector3 abductPos, float abductForce, float abductRange);

	virtual void updateForce(PxParticle* particle, double dt) override;

	void Activate();

};

