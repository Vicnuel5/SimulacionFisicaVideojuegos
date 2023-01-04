#pragma once

#include "PxPickableParticle.h"

class Puerta : public PxPickableParticle
{
	bool hasBeenPicked;
	physx::PxTransform initTr;

public:
	Puerta(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~Puerta() = default;

	virtual void integrate(float dt) override;
	virtual void setPick(bool b) override;
};

class PuertaNevera : public Puerta
{

public:
	PuertaNevera(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~PuertaNevera() = default;
};

class PuertaNevera2 : public Puerta
{

public:
	PuertaNevera2(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~PuertaNevera2() = default;
};

class PuertaCajon : public Puerta
{

public:
	PuertaCajon(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~PuertaCajon() = default;
};

