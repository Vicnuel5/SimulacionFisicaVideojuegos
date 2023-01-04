#include "PxRigid.h"

using namespace physx;

PxRigid::PxRigid(PxPhysics* physx, PxTransform& pose) 
{
	rigid = physx->createRigidStatic(pose);
}

PxRigid::~PxRigid()
{
	DeregisterRenderItem(render);
}

PxRigidGroup::PxRigidGroup()
{
}

PxRigidGroup::~PxRigidGroup()
{
	for (auto r : rigids)
		delete r;
}
