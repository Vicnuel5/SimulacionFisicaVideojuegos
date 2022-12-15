#pragma once

#include "PxForceGenerator.h" 
#include "../RenderUtils.hpp"


class PxWindFG : public PxForceGenerator
{

public:
	PxWindFG(const Vector3& vel, const Vector3& pos, double area);
	virtual ~PxWindFG();

	inline void setDrag(float k1_, float k2_) { k1 = k1_; k2 = k2_; }

	virtual void updateForce(PxRigidDynamic* particle, double dt);

protected:
	Vector3 windVel;
	Vector3 windPos;
	double radius;
	RenderItem* windArea;

	float k1;
	float k2;
};

