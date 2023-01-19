#include "Comida.h"

using namespace physx;

Cebolla::Cebolla(physx::PxPhysics* physx, physx::PxTransform& pose) :
	PxPickableParticle(physx, pose)
{
	Vector4 color(1, 1, 1, 1);

	PxShape* s_comida = CreateShape(PxSphereGeometry(1), physx->createMaterial(0.5, 0.5, 1));
	particle->attachShape(*s_comida);
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(1.5);

	renderItems.push_back(new RenderItem(s_comida, particle, color));
}

Tomate::Tomate(physx::PxPhysics* physx, physx::PxTransform& pose) : PxPickableParticle(physx, pose)
{
	Vector4 color(1, 0, 0, 1);
	
	PxShape* s_comida = CreateShape(PxSphereGeometry(1), physx->createMaterial(0.25, 0.25, 0.5));
	particle->attachShape(*s_comida);
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(2);

	renderItems.push_back(new RenderItem(s_comida, particle, color));

	addItem(new PxTransform(pose), PxVec3(0, 0.95, 0),
		CreateShape(PxBoxGeometry(Vector3(0.5, 0.1, 0.5))), Vector4(0.2, 0.5, 0.2, 1));
}

Tortilla::Tortilla(physx::PxPhysics* physx, physx::PxTransform& pose)
	: PxPickableParticle(physx, pose)
{
	float ancho = 2.5;
	float alto = 0.2;

	Vector4 color(0.5, 0.7, 0.1, 1);

	Vector3 size(ancho, alto, ancho);
	PxShape* s_sarten = CreateShape(PxBoxGeometry(size), physx->createMaterial(1, 1, 0));
	particle->attachShape(*s_sarten);
	particle->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y });
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(3);

	renderItems.push_back(new RenderItem(s_sarten, particle, color));
}

Agua::Agua(physx::PxPhysics* physx, physx::PxTransform& pose)
	: PxPickableParticle(physx, pose)
{
	float ancho = 1;
	float alto = 3.5;

	Vector3 size(ancho, alto, ancho);
	PxShape* s_aceite = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0.5, 0));
	particle->attachShape(*s_aceite);
	particle->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y });
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(0.6);

	renderItems.push_back(new RenderItem(s_aceite, particle, PxVec4(0.23, 0.51, 0.72, 1)));

	addItem(new PxTransform(pose), PxVec3(0, alto + ancho / 3, 0),
		CreateShape(PxBoxGeometry(Vector3(ancho / 2, ancho / 2, ancho / 2))),
		PxVec4(0.1, 0.1, 0.95, 1));

	pickedOffsetP = PxVec3(0, 2, 0);
}

SoporteComida::SoporteComida(physx::PxPhysics* physx, physx::PxTransform& pose) 
	: PxParticle(physx, pose)
{
	Vector4 color(0.1, 0.1, 0.1, 1);

	Vector3 size(2, 0.5, 0.5);
	PxShape* s_sarten = CreateShape(PxBoxGeometry(size), physx->createMaterial(1, 1, 0));
	particle->attachShape(*s_sarten);
	particle->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y });
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(0.0001);

	renderItems.push_back(new RenderItem(s_sarten, particle, color));
}
