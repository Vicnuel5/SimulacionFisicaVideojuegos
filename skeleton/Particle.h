#pragma once

#include "core.hpp"
#include "RenderUtils.hpp"

class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float D, float Minv);
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float D, float Minv, physx::PxShape* shape);
	Particle(Vector3 Pos, physx::PxShape* shape);
	~Particle();

	void integrate(double t);

	physx::PxTransform getPos();
	void setColor(Vector4 color);

private:
	Vector3 vel;
	Vector3 acc;
	float d;
	float mInv;
	physx::PxTransform pose;
	RenderItem* renderItem;
};

