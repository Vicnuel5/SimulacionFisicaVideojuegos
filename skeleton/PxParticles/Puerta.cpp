#include "Puerta.h"

using namespace physx;

PuertaNevera::PuertaNevera(physx::PxPhysics* physx, physx::PxTransform& pose) :
	Puerta(physx, pose)
{
	Vector3 size(7, 14.5, 0.5);
	PxShape* s_puertaNevera = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	particle->attachShape(*s_puertaNevera);
	particle->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y });
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(0.1);

	renderItems.push_back(new RenderItem(s_puertaNevera, particle, { 0.7, 0.7, 0.9, 1 }));

	addItem(new PxTransform(pose), PxVec3(-5.5, 2, 0.5), 
		CreateShape(PxBoxGeometry(Vector3(0.5, 3, 0.5))), {0.4,0.4,0.5,1});

	pickedOffsetP = PxVec3(0, -5, 0);
}

PuertaNevera2::PuertaNevera2(physx::PxPhysics* physx, physx::PxTransform& pose) :
	Puerta(physx, pose)
{
	Vector3 size(7, 4.5, 0.5);
	PxShape* s_puertaNevera = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	particle->attachShape(*s_puertaNevera);
	particle->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y });
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(0.1);

	renderItems.push_back(new RenderItem(s_puertaNevera, particle, { 0.7, 0.7, 0.9, 1 }));

	addItem(new PxTransform(pose), PxVec3(-5.5, 0, 0.5),
		CreateShape(PxBoxGeometry(Vector3(0.5, 2, 0.5))), { 0.4,0.4,0.5,1 });

	pickedOffsetP = PxVec3(0, -5, 0);
}

PuertaCajon::PuertaCajon(physx::PxPhysics* physx, physx::PxTransform& pose) :
	Puerta(physx, pose)
{
	Vector3 size(7.5, 5, 0.25);
	PxShape* s_puertaNevera = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	particle->attachShape(*s_puertaNevera);
	particle->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y });
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(0.1);

	renderItems.push_back(new RenderItem(s_puertaNevera, particle, { 0.5, 0.25, 0, 1 }));

	addItem(new PxTransform(pose), PxVec3(0, 0, 0.25),
		CreateShape(PxBoxGeometry(Vector3(4, 0.5, 0.5))), { 0.25, 0.125, 0, 1 });

	pickedOffsetP = PxVec3(0, -5, 0);
}

Puerta::Puerta(physx::PxPhysics* physx, physx::PxTransform& pose) :
	PxPickableParticle(physx, pose), hasBeenPicked(false)
{
	initTr = PxTransform(pose);
}

void Puerta::integrate(float dt)
{
	//PxParticle::integrate(dt);
	if (hasBeenPicked) {
		PxParticle::integrate(dt);
	}
	else {
		particle->setGlobalPose(PxTransform(initTr));
	}
}

void Puerta::setPick(bool b)
{
	if (b) hasBeenPicked = true;
	PxParticle::setPick(b);

}
