#pragma once

#include "PxRigid.h"

class SostenCebollas : public PxRigid
{
public:
	SostenCebollas(physx::PxPhysics* physx, physx::PxTransform& pose,
		physx::PxVec3 size, physx::PxVec4 color);
	virtual ~SostenCebollas() = default;
};

class Suelo : public PxRigid
{
public: 
	Suelo(physx::PxPhysics* physx, physx::PxTransform& pose, 
		physx::PxVec3 size, physx::PxVec4 color);
	virtual ~Suelo() = default;
};

class Columna : public PxRigid
{
public:
	Columna(physx::PxPhysics* physx, physx::PxTransform& pose, 
		physx::PxVec3 size, physx::PxVec4 color);
	virtual ~Columna() = default;
};

class Tarima : public PxRigid
{
public:
	Tarima(physx::PxPhysics* physx, physx::PxTransform& pose, 
		physx::PxVec3 size, physx::PxVec4 color);
	virtual ~Tarima() = default;
};

class ParedEO : public PxRigid
{
public:
	ParedEO(physx::PxPhysics* physx, physx::PxTransform& pose,
		physx::PxVec3 size, physx::PxVec4 color);
	virtual ~ParedEO() = default;
};

class ParedN : public PxRigid
{
public:
	ParedN(physx::PxPhysics* physx, physx::PxTransform& pose,
		physx::PxVec3 size, physx::PxVec4 color);
	virtual ~ParedN() = default;
};

class ComponenteNevera : public PxRigid
{
public:
	ComponenteNevera(physx::PxPhysics* physx, physx::PxTransform& pose,
		physx::PxVec3 size, physx::PxVec4 color);
	virtual ~ComponenteNevera() = default;
};

class Nevera : public PxRigidGroup
{
public:
	Nevera(physx::PxPhysics* physx, physx::PxTransform& pose, physx::PxVec4 color);
	virtual ~Nevera() = default;
};

class PataTarima : public PxRigid
{
public:
	PataTarima(physx::PxPhysics* physx, physx::PxTransform& pose,
		physx::PxVec3 size, physx::PxVec4 color);
	virtual ~PataTarima() = default;
};

class ComponenteCajon : public PxRigid
{
public:
	ComponenteCajon(physx::PxPhysics* physx, physx::PxTransform& pose,
		physx::PxVec3 size, physx::PxVec4 color);
	virtual ~ComponenteCajon() = default;
};

class Cajon : public PxRigidGroup
{
public:
	Cajon(physx::PxPhysics* physx, physx::PxTransform& pose, physx::PxVec4 color);
	virtual ~Cajon() = default;
};







