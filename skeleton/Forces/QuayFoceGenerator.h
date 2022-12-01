#pragma once

#include "ForceGenerator.h"

class QuayFoceGenerator : public ForceGenerator
{

public: 
	QuayFoceGenerator(Particle* p, double longReposo, double k);
	virtual void updateForce(Particle* particle, double t);

	void setK(double k);

	virtual ~QuayFoceGenerator() = default;

protected:
	double longReposo;
	double K;
	Particle* myParticle;

};

