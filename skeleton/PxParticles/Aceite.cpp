#include "Aceite.h"

#include "../PxParticleSystems/OilSystem.h"

using namespace physx;

Aceite::Aceite(physx::PxPhysics* physx, physx::PxTransform& pose, OilSystem* oilSystem)
	: PxPickableParticle(physx, pose), oilSystem(oilSystem)
{
	

	float ancho = 1;
	float alto = 3.5;

	Vector3 size(ancho, alto, ancho);
	PxShape* s_aceite = CreateShape(PxBoxGeometry(size), physx->createMaterial(0.5, 0.5, 0));
	particle->attachShape(*s_aceite);
	particle->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y });
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(1);

	renderItems.push_back(new RenderItem(s_aceite, particle, PxVec4(0.5, 0.5, 0.2, 1)));

	taponTr = new PxTransform(pose);
	addItem(taponTr, PxVec3(0, alto + ancho/ 3, 0),
		CreateShape(PxBoxGeometry(Vector3(ancho / 2, ancho / 2, ancho / 2))), 
		PxVec4(0.5, 0.5, 0.2, 1));



	pickedOffsetP = PxVec3(0, 2, 0);
	pickedOffsetQ = PxQuat(3.1415, PxVec3(0, 0, 1));
}

Aceite::~Aceite()
{
	delete oilSystem;
	delete taponTr;
}

void Aceite::integrate(float dt)
{
	PxParticle::integrate(dt);
	oilSystem->integrate(dt);
}

void Aceite::interact()
{
	oilSystem->Activate(taponTr->p + Vector3(0, -0.5, 0));
}

ParticleAceite::ParticleAceite(physx::PxPhysics* physx, physx::PxTransform& pose) 
	: PxParticle(physx, pose)
{
	PxShape* s_aceite = CreateShape(PxSphereGeometry(0.15), physx->createMaterial(0, 0, 0));
	particle->attachShape(*s_aceite);
	//particle->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y });
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(0.000001);

	renderItems.push_back(new RenderItem(s_aceite, particle, PxVec4(0.5, 0.5, 0.2, 1)));
}
