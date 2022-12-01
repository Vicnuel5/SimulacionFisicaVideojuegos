#pragma once

#include "ForceGenerator.h"

class FlotationForceGenerator : public ForceGenerator
{
public:
	FlotationForceGenerator(Vector3 pos, Vector3 otherDimension);
	virtual void updateForce(Particle* p, double duration) override;
	virtual ~FlotationForceGenerator();

protected:
	Particle* water;
	double otherHeight;
	double otherVolume;
};

