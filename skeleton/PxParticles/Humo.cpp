#include "Humo.h"

using namespace physx;

ParticleHumo::ParticleHumo(physx::PxPhysics* physx, physx::PxTransform& pose) :
	PxParticle(physx, pose), cont(0), flowTime(0)
{
	PxShape* s_aceite = CreateShape(PxSphereGeometry(0.15), physx->createMaterial(0, 0, 0));
	particle->attachShape(*s_aceite);
	//particle->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y });
	particle->setLinearDamping(0.99);
	particle->setAngularDamping(0.99);
	particle->setMass(0.000001);

	renderItems.push_back(new RenderItem(s_aceite, particle, PxVec4(0.3, 0.3, 0.3, 1)));
}
