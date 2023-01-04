#include "Vitro.h"

using namespace physx;

Vitro::Vitro(physx::PxPhysics* physx, physx::PxTransform& pose,
	physx::PxVec3 size, physx::PxVec4 color) : PxRigid(physx, pose)
{
	encendidad = false;

	PxShape* shape = CreateShape(PxBoxGeometry(size), physx->createMaterial(0, 0, 0));
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);

	fuego_tr = PxTransform(pose);
	fuego_tr.p = fuego_tr.p + Vector3(0, 0.2, 0);
	fuego = new RenderItem(CreateShape(PxBoxGeometry(PxVec3(size.x - 1, 0.1, size.x - 1))),
		&fuego_tr, PxVec4(0.1, 0.1, 0.1, 1));
}

Vitro::~Vitro()
{
	delete fuego;
}

void Vitro::turnOnOff()
{
	if (encendidad) {
		fuego->color = PxVec4(0.1, 0.1, 0.1, 1);
	}
	else {
		fuego->color = PxVec4(1, 0, 0, 1);
	}

	encendidad = !encendidad;
}
