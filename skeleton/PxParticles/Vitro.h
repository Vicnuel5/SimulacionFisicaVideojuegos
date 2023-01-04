#pragma once

#include "PxRigid.h"

class Vitro : public PxRigid
{
	RenderItem* fuego;
	physx::PxTransform fuego_tr;

	bool encendidad;

public:
	Vitro(physx::PxPhysics* physx, physx::PxTransform& pose,
		physx::PxVec3 size, physx::PxVec4 color);
	virtual ~Vitro();

	void turnOnOff();
	bool turnOn() { return encendidad; }
};

