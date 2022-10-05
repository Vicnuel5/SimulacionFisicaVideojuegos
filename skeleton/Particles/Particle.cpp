#include "Particle.h"

Particle::Particle(Vector3 Pos) :
	vel({0,0,0}), acc({0,0,0}), d(1), mInv(0)
{
	pose = physx::PxTransform(Pos.x, Pos.y, Pos.z);
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0)), &pose, { 0.5, 0.0, 0.5, 1 });
}

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float D, float Minv) :
	vel(Vel), acc(Acc), d(D), mInv(Minv)
{	

	pose = physx::PxTransform(Pos.x, Pos.y, Pos.z);
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0)), &pose, { 0.5, 0.0, 0.5, 1 });
}

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float D, float Minv, physx::PxShape* shape) :
	vel(Vel), acc(Acc), d(D), mInv(Minv)
{
	pose = physx::PxTransform(Pos.x, Pos.y, Pos.z);
	renderItem = new RenderItem(shape, &pose, { 0.5, 0.5, 0, 1 });
}

Particle::Particle(Vector3 Pos, physx::PxShape* shape) :
	vel(Vector3()), acc(Vector3()), d(1), mInv(0)
{
	pose = physx::PxTransform(Pos.x, Pos.y, Pos.z);
	renderItem = new RenderItem(shape, &pose, {});
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(double t)
{
	pose = physx::PxTransform(pose.p.x + vel.x * t, pose.p.y + vel.y * t, pose.p.z + vel.z * t);

	vel += acc * t;

	vel *= powf(d, t);
}

void Particle::setPos(Vector3 newPos)
{
	pose = physx::PxTransform(newPos.x, newPos.y, newPos.z);
}

Vector3 Particle::getPos()
{
	return pose.p;
}

void Particle::setVel(Vector3 newVel)
{
	vel = newVel;
}

void Particle::setAcc(Vector3 newAcc)
{
	acc = newAcc;
}

void Particle::setD(float newDump)
{
	d = newDump;
}

void Particle::setMass(float newMass)
{
	mInv = newMass;
}

void Particle::setColor(Vector4 color)
{
	renderItem->color = color;
}
