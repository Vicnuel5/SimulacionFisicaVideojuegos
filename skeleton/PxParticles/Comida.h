#pragma once

#include "PxPickableParticle.h"
class Cebolla : public PxPickableParticle
{
public:
	Cebolla(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~Cebolla() = default;
};

class Tomate : public PxPickableParticle
{
public:
	Tomate(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~Tomate() = default;
};

class Tortilla : public PxPickableParticle
{
public:
	Tortilla(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~Tortilla() = default;
};

class Agua : public PxPickableParticle
{
public:
	Agua(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~Agua() = default;
};

class SoporteComida : public PxParticle
{
public:
	SoporteComida(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~SoporteComida() = default;
};

