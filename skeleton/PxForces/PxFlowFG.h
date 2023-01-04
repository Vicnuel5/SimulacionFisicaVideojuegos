#pragma once

#include "PxForceGenerator.h"

class PxFlowFG : public PxForceGenerator
{
public:
	PxFlowFG();

	virtual void updateForce(PxParticle* particle, double dt) override;

};




