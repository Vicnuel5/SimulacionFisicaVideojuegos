#pragma once

#include <list>

#include <PxPhysicsAPI.h>

#include "../core.hpp"
#include "../RenderUtils.hpp"

#define ITEM_DIST 20
#define PICK_RANGE 10


class PxParticle
{
	
protected:
	std::list<std::pair<physx::PxTransform*, physx::PxVec3>> items;
	std::list<RenderItem*> renderItems;

	void addItem(physx::PxTransform* tr, physx::PxVec3 offset, physx::PxShape* shape, physx::PxVec4 color);
	void addItem(physx::PxTransform* tr, physx::PxVec3 offset, physx::PxShape* shape);

	bool isPicked;
	physx::PxVec3 pickedOffsetP;
	physx::PxQuat pickedOffsetQ;

public:
	physx::PxRigidDynamic* particle;

	PxParticle(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~PxParticle();

	virtual void integrate(float dt);

	virtual bool canPick() { return false; }
	virtual bool canInteract() { return false; }
	virtual void interact() {  };
	virtual void setPick(bool b);


};

