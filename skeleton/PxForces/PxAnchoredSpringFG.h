#pragma once

#include "PxQuayFG.h"


class PxAnchoredSpringFG : public PxQuayFG
{

public:
	PxAnchoredSpringFG(PxParticle* particle, double longReposo, double k);
	~PxAnchoredSpringFG();
};

