#pragma once

#include "PxForceGenerator.h"

class PxQuayFG : public PxForceGenerator
{

public:
	PxQuayFG(PxParticle* p, double longReposo, double k);
	virtual void updateForce(PxParticle* particle, double t);

	void setK(double k);

	virtual ~PxQuayFG() = default;

protected:
	double longReposo;
	double K;
	PxParticle* myParticle;

};

