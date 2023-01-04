#pragma once
#include "PxForceGenerator.h"

class PxRotationFG : public PxForceGenerator
{

public:
	PxRotationFG();

	virtual void updateForce(PxParticle* particle, double dt) override;

};

