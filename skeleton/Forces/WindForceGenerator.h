#pragma once

#include "DragGenerator.h" 
#include "../core.hpp"

class WindForceGenerator : public DragGenerator
{
	virtual Vector3 getVel(Vector3 pPos);

public:
	WindForceGenerator(const Vector3& vel, const Vector3& pos, double area);
	virtual ~WindForceGenerator();

	virtual void updateForce(Particle* particle, double t);

protected:
	Vector3 windVel;
	Vector3 windPos;
	double radius;
	RenderItem* windArea;
};

