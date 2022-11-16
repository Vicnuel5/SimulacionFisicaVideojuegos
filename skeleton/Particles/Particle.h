#pragma once

#include "../core.hpp"
#include "../RenderUtils.hpp"

class Particle
{
public:
	Particle(Vector3 Pos);
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float D, float InvMass);
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float D, float InvMass, physx::PxShape* shape);
	Particle(Vector3 Pos, physx::PxShape* shape);
	~Particle();

	void integrate(double t);

	void setPos(Vector3 newPos);
	Vector3 getPos();

	void setVel(Vector3 newVel);
	Vector3 getVel();

	void setAcc(Vector3 newAcc);

	void setDump(float newDump);

	void setInvMass(float newInvMass);
	void setMass(float newMass);
	float getInvMass();
	float getMass();

	void setColor(Vector4 color);

	void addForce(const Vector3& f);

private:
	Vector3 vel;
	Vector3 acc;
	float d;
	float invMass;
	physx::PxTransform pose;
	RenderItem* renderItem;

	Vector3 force;

	void clearForce();
	
};

