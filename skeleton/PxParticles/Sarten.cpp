#include "Sarten.h"

#include "../PxParticleSystems/SmokeSystem.h"

using namespace physx;

Sarten::Sarten(physx::PxPhysics* physx, physx::PxTransform& pose, SmokeSystem* smokeSystem) :
	PxPickableParticle(physx, pose), smokeSystem(smokeSystem)
{
	float ancho = 4;
	float alto = 0.4;

	Vector4 color(0.1, 0.1, 0.1, 1);

	Vector3 size(ancho, alto, ancho);
	PxShape* s_sarten = CreateShape(PxBoxGeometry(size), physx->createMaterial(1, 1, 0));
	particle->attachShape(*s_sarten);
	particle->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y - 100 });
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(0.1);

	renderItems.push_back(new RenderItem(s_sarten, particle, color));


	addItem(new PxTransform(pose), PxVec3(0, alto, ancho),
		CreateShape(PxBoxGeometry(Vector3(ancho, alto, alto))), color);
	addItem(new PxTransform(pose), PxVec3(0, alto, -ancho),
		CreateShape(PxBoxGeometry(Vector3(ancho, alto, alto))), color);

	addItem(new PxTransform(pose), PxVec3(ancho, alto, 0),
		CreateShape(PxBoxGeometry(Vector3(alto, alto, ancho))), color);
	addItem(new PxTransform(pose), PxVec3(-ancho, alto, 0),
		CreateShape(PxBoxGeometry(Vector3(alto, alto, ancho))), color);

	addItem(new PxTransform(pose), PxVec3(0, 0, ancho * 1.5),
		CreateShape(PxBoxGeometry(Vector3(alto * 1.5, alto, ancho * 1.5))), color);

	addItem(new PxTransform(pose), PxVec3(0, 0, ancho * 2.5),
		CreateShape(PxBoxGeometry(Vector3(alto * 1.5 * 1.25, alto * 1.25, ancho / 3))), PxVec4(1,0,0,1));


	tamAceite = Vector3(0.1, 0.1, 0.1);
	


	pickedOffsetP = PxVec3(0, -5, 0);
}

void Sarten::integrate(float dt)
{
	PxParticle::integrate(dt);
	smokeSystem->integrate(dt);
}

void Sarten::echarAceite()
{
	if (tamAceite.x <= 0)
		addItem(new PxTransform(particle->getGlobalPose().p), PxVec3(0, 0.31, 0),
			CreateShape(PxBoxGeometry(tamAceite)), PxVec4(0, 0.5, 0, 1));
	else if (tamAceite.x < 3) {
		DeregisterRenderItem(renderItems.back());
		renderItems.pop_back();
		tamAceite += PxVec3(0.05, 0, 0.05);
		addItem(new PxTransform(particle->getGlobalPose().p), PxVec3(0, 0.31, 0),
			CreateShape(PxBoxGeometry(tamAceite)), PxVec4(0, 0.5, 0, 1));
	}	
}

void Sarten::quemarAceite()
{

	smokeSystem->Activate(particle->getGlobalPose().p + PxVec3(0, 0.5, 0));

}


