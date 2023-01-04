#include "AllRigids.h"

using namespace physx;

Suelo::Suelo(physx::PxPhysics* physx, physx::PxTransform& pose, 
	physx::PxVec3 size, PxVec4 color) : PxRigid(physx, pose)
{
	PxShape* shape = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
}

Columna::Columna(physx::PxPhysics* physx, physx::PxTransform& pose,
	physx::PxVec3 size, PxVec4 color) : PxRigid(physx, pose)
{
	PxShape* shape = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
}

Tarima::Tarima(physx::PxPhysics* physx, physx::PxTransform& pose,
	physx::PxVec3 size, PxVec4 color) : PxRigid(physx, pose)
{
	PxShape* shape = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
}

ParedEO::ParedEO(physx::PxPhysics* physx, physx::PxTransform& pose, 
	physx::PxVec3 size, physx::PxVec4 color) : PxRigid(physx, pose)
{
	PxShape* shape = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
}

ParedN::ParedN(physx::PxPhysics* physx, physx::PxTransform& pose, 
	physx::PxVec3 size, physx::PxVec4 color) : PxRigid(physx, pose)
{
	PxShape* shape = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
}

ComponenteNevera::ComponenteNevera(physx::PxPhysics* physx, physx::PxTransform& pose,
	physx::PxVec3 size, physx::PxVec4 color) : PxRigid(physx, pose)
{
	PxShape* shape = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
}

Nevera::Nevera(physx::PxPhysics* physx, physx::PxTransform& pose, physx::PxVec4 color)
{
	float d = 7.5;
	float h = 20;

	PxTransform tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, 0, -d);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, h, 0.5), color));

	PxVec3 size = PxVec3(0.5, h, d);

	 tr = PxTransform(pose);
	tr.p = tr.p + Vector3(d, 0, 0);
	rigids.push_back(new ComponenteNevera(physx, tr,
		size, color));

	 tr = PxTransform(pose);
	tr.p = tr.p + Vector3(-d, 0, 0);
	rigids.push_back(new ComponenteNevera(physx, tr,
		size, color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, h -0.5, 0);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, 0.5, d), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, -h + 0.5, 0);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, 0.5, d), color));

	
	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, h-10, 0);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, 1, d), color));

	float d2 = d - 1;

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, (h - 10) - 7.5, -1);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, 0.5, d2), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, (h - 10) - 15, -1);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, 0.5, d2), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, (h - 10) - 22.5, -1);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, 0.5, d2), color));

}

PataTarima::PataTarima(physx::PxPhysics* physx, physx::PxTransform& pose,
	physx::PxVec3 size, physx::PxVec4 color) : PxRigid(physx, pose)
{
	PxShape* shape = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
}

ComponenteCajon::ComponenteCajon(physx::PxPhysics* physx, physx::PxTransform& pose,
	physx::PxVec3 size, physx::PxVec4 color) : PxRigid(physx, pose)
{
	PxShape* shape = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
}

Cajon::Cajon(physx::PxPhysics* physx, physx::PxTransform& pose, physx::PxVec4 color)
{
	float d = 7.5;
	float h = 5;

	PxTransform tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, h, 0);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, 0.25, d), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, -h, 0);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, 0.25, d), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, 0, -0.5);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, 0.25, d -0.5), color));


	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(-d, 0, 0);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(0.25, d - 1.5, d), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(d, 0, 0);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(0.25, d - 1.5, d), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, 0, -d);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, h, 0.25), color));
}

ComponenteCampana::ComponenteCampana(physx::PxPhysics* physx, physx::PxTransform& pose,
	physx::PxVec3 size, physx::PxVec4 color) : PxRigid(physx, pose)
{
	PxShape* shape = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
}

CampanaExtractora::CampanaExtractora(physx::PxPhysics* physx, physx::PxTransform& pose, physx::PxVec4 color)
{
	float d = 4;
	float dd = 10;

	PxTransform tr = PxTransform(pose);
	tr.p = tr.p + Vector3(dd, 0, 0);
	tr.q = tr.q * PxQuat(3.14 / 4, PxVec3(0, 0, 1));
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(0.25, d, d * 2.5), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(-dd, 0, 0);
	tr.q = tr.q * PxQuat(-3.14 / 4, PxVec3(0, 0, 1));
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(0.25, d, d * 2.5), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(-dd + 2.75, -2.75, d * 2.5);
	tr.q = tr.q * PxQuat(-3.14 / 4, PxVec3(0, 0, 1));
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, d, 0.25), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(dd - 2.75, -2.75, d * 2.5);
	tr.q = tr.q * PxQuat(-3.14 / 4, PxVec3(0, 0, 1));
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d, d, 0.25), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, -1.2, d * 2.5);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d * 2 - 0.5, d, 0.25), color));

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, 15, -5);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(d * 1.5, d * 3, d*1.5), color));

	float a = 9;

	tr = PxTransform(pose);
	tr.p = tr.p + Vector3(0, 2.5, 0);
	rigids.push_back(new ComponenteNevera(physx, tr,
		PxVec3(a - 1.5, 0.25, a + 1), color));

}


