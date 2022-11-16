#pragma once

#include "WindForceGenerator.h"

class WhirlwindForceGenerator : public WindForceGenerator
{
	virtual Vector3 getVel(Vector3 pVel) override;

public:
	WhirlwindForceGenerator(const Vector3& pos, double area, double k);
	~WhirlwindForceGenerator() {};

protected:
	double K;
};