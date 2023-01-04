#include "PxParticle.h"

using namespace physx;

#include <iostream>


PxParticle::PxParticle(PxPhysics* physx, PxTransform& pose) :
	isPicked(false), pickedOffsetP(PxVec3(0,0,0)), pickedOffsetQ(PxQuat(0, PxVec3(0,1,0)))
{
	particle = physx->createRigidDynamic(pose);
}

PxParticle::~PxParticle()
{
	for (auto i : renderItems) {
		DeregisterRenderItem(i);
	}

	for (auto i : items) {
		delete i.first;
	}
}

void PxParticle::integrate(float dt)
{
	PxTransform tr = particle->getGlobalPose();

	if (isPicked) {

		auto c = GetCamera();
		PxTransform newTr = particle->getGlobalPose();

		PxVec3 dist = c->getEye() + c->getDir().getNormalized() * ITEM_DIST;
		newTr.p = dist + pickedOffsetP;

		auto q = c->getTransform().q;
		auto rot = PxQuat(3.1415 / 2, PxVec3(0, 0, 1));
		q = q * rot * pickedOffsetQ;
		newTr.q = q;

		particle->setGlobalPose(newTr);

		tr = particle->getGlobalPose();
	}

	for (auto i : items) {
		PxTransform newTr = PxTransform(tr);
		newTr.p = tr.transform(i.second);
		*i.first = newTr;
	}
}

void PxParticle::setPick(bool b)
{
	isPicked = b;
	if (!b) {
		particle->setLinearVelocity(PxVec3(0, 0, 0));
		particle->setAngularVelocity(PxVec3(0, 0, 0));
	}
}

void PxParticle::addItem(physx::PxTransform* tr, physx::PxVec3 offset, physx::PxShape* shape, physx::PxVec4 color)
{
	tr->p = tr->p + offset;

	items.push_back({ tr, offset });
	renderItems.push_back(new RenderItem(shape, tr, color));
}

void PxParticle::addItem(physx::PxTransform* tr, physx::PxVec3 offset, physx::PxShape* shape)
{
	addItem(tr, offset, shape, { 1,1,1,1 });
}

