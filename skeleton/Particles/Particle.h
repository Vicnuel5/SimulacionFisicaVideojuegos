#pragma once

#include "../core.hpp"
#include "../RenderUtils.hpp"

class Particle
{
public:
	Particle(Vector3 Pos);
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float D, float Minv);
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float D, float Minv, physx::PxShape* shape);
	Particle(Vector3 Pos, physx::PxShape* shape);
	~Particle();

	void integrate(double t);

	void setPos(Vector3 newPos);
	Vector3 getPos();

	void setVel(Vector3 newVel);

	void setAcc(Vector3 newAcc);

	void setDump(float newDump);

	void setMass(float newMass);
	float getMass();

	void setColor(Vector4 color);

	void addForce(const Vector3& f);

private:
	Vector3 vel;
	Vector3 acc;
	float d;
	float mInv;
	physx::PxTransform pose;
	RenderItem* renderItem;

	Vector3 force;

	void clearForce();
	
};

