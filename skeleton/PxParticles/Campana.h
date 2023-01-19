#pragma once

#include "PxRigid.h"

class SmokeSystem;
	 
class CampanaExtractora : public PxRigidGroup
{
	SmokeSystem* smokeSys;
	bool active;

	RenderItem* luz;

public:
	CampanaExtractora(physx::PxPhysics* physx, physx::PxTransform& pose, physx::PxVec4 color, SmokeSystem* smokeSys);
	virtual ~CampanaExtractora();


	void turnOnOff();
};

class ComponenteCampana : public PxRigid
{
public:
	ComponenteCampana(physx::PxPhysics* physx, physx::PxTransform& pose,
		physx::PxVec3 size, physx::PxVec4 color);
	virtual ~ComponenteCampana() = default;
};

