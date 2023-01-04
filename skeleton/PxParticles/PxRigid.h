#pragma once

#include <list>

#include <PxPhysicsAPI.h>

#include "../core.hpp"
#include "../RenderUtils.hpp"

class PxRigid
{
	
protected:
	RenderItem* render;
	

public:
	PxRigid(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~PxRigid();

	physx::PxRigidStatic* rigid;

};

class PxRigidGroup
{

public:
	PxRigidGroup();
	virtual ~PxRigidGroup();

	std::list<PxRigid*> rigids;
};

