#pragma once

#include "QuayFoceGenerator.h"

class AnchoredSpringForceGenerator : public QuayFoceGenerator
{

public:
	AnchoredSpringForceGenerator(Vector3 Pos, double longReposo, double k);
	~AnchoredSpringForceGenerator();
};

