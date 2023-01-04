#pragma once

#include "PxPickableParticle.h"

class OilSystem;
class Sarten;

class Aceite : public PxPickableParticle
{
	OilSystem* oilSystem;
	physx::PxTransform* taponTr;

public:
	Aceite(physx::PxPhysics* physx, physx::PxTransform& pose, OilSystem* oilSystem);
	virtual ~Aceite();

	virtual bool canInteract() override { return true; }

	virtual void integrate(float dt) override;

	virtual void interact() override;
};

class ParticleAceite : public PxParticle
{
	OilSystem* oilSystem;
	physx::PxTransform* taponTr;

public:
	ParticleAceite(physx::PxPhysics* physx, physx::PxTransform& pose);
	~ParticleAceite() = default;
};

