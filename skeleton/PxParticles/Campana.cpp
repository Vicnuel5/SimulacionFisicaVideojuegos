#include "Campana.h"

#include "../PxParticleSystems/SmokeSystem.h"

using namespace physx;

CampanaExtractora::CampanaExtractora(physx::PxPhysics* physx, physx::PxTransform& pose, physx::PxVec4 color, SmokeSystem* smokeSys) :
	active(false), smokeSys(smokeSys)
{
	float d = 4;
	float dd = 10;

	PxTransform tr = PxTransform(pose);
	tr.p = tr.p + Vector3(dd, 0, 0);
	tr.q = tr.q * PxQuat(3.14 / 4, PxVec3(0, 0, 1));
	rigids.push_back(new ComponenteCampana(physx, tr,
		PxVec3(0.25, d, d * 2.5), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(-dd, 0, 0);
	tr.q = tr.q * PxQuat(-3.14 / 4, PxVec3(0, 0, 1));
	rigids.push_back(new ComponenteCampana(physx, tr,
		PxVec3(0.25, d, d * 2.5), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(-dd + 2.75, -2.75, d * 2.5);
	tr.q = tr.q * PxQuat(-3.14 / 4, PxVec3(0, 0, 1));
	rigids.push_back(new ComponenteCampana(physx, tr,
		PxVec3(d, d, 0.25), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(dd - 2.75, -2.75, d * 2.5);
	tr.q = tr.q * PxQuat(-3.14 / 4, PxVec3(0, 0, 1));
	rigids.push_back(new ComponenteCampana(physx, tr,
		PxVec3(d, d, 0.25), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, -1.2, d * 2.5);
	rigids.push_back(new ComponenteCampana(physx, tr,
		PxVec3(d * 2 - 0.5, d, 0.25), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, 15, -5);
	rigids.push_back(new ComponenteCampana(physx, tr,
		PxVec3(d * 1.5, d * 3, d * 1.5), PxVec4(0.2, 0.2, 0.2, 1)));

	float a = 9;

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, 2.5, 0);
	rigids.push_back(new ComponenteCampana(physx, tr,
		PxVec3(a - 1.5, 0.25, a + 1), color));


	PxTransform* ltr = new PxTransform(pose);
	ltr->p = ltr->p + Vector3(dd - 2.75, -7, dd + 0.25);
	//ltr->q = ltr->q * PxQuat(-3.14, PxVec3(0, 0, 1));
	luz = new RenderItem(CreateShape(PxSphereGeometry(0.55)),
		ltr, PxVec4(0.1, 0.1, 0.1, 1));

}

CampanaExtractora::~CampanaExtractora()
{
	RegisterRenderItem(luz);
}

void CampanaExtractora::turnOnOff()
{
	active = !active;
	smokeSys->ActivateCampana();
	if (active)
		luz->color = PxVec4(1, 0, 0, 1);		
	else 
		luz->color = PxVec4(0.1, 0.1, 0.1, 1);
}

ComponenteCampana::ComponenteCampana(physx::PxPhysics* physx, physx::PxTransform& pose,
	physx::PxVec3 size, physx::PxVec4 color) : PxRigid(physx, pose)
{
	PxShape* shape = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
}
