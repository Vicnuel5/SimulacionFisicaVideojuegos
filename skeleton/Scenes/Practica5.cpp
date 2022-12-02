#include "Practica5.h"
#include "../RenderUtils.hpp"

using namespace physx;

void Practica5::s_init()
{
	PxRigidStatic* suelo = myPhysics->createRigidStatic(PxTransform({ 0, 0, 0 }));
	PxShape* shape = CreateShape(PxBoxGeometry(100, 0.1, 100));
	suelo->attachShape(*shape);
	auto item = new RenderItem(shape, suelo, { 0.8, 0.8,0.8, 1 });
	myScene->addActor(*suelo);

	PxRigidStatic* pared = myPhysics->createRigidStatic(PxTransform({ 10, 10, -30 }));
	PxShape* shape_suelo = CreateShape(PxBoxGeometry(40, 20, 5));
	pared->attachShape(*shape_suelo);
	item = new RenderItem(shape_suelo, pared, { 0.8, 0.8,0.8, 1 });
	myScene->addActor(*pared);


	PxRigidDynamic* bola = myPhysics->createRigidDynamic(PxTransform({ 0, 20, 0 }));
	PxShape* shape_bola = CreateShape(PxSphereGeometry(1));
	bola->attachShape(*shape_bola);
	item = new RenderItem(shape_bola, bola, { 1, 1,0, 1 });
	bola->addForce({ 0, -9.8, 9 });
	myScene->addActor(*bola);

	

}

void Practica5::s_clean()
{
}

void Practica5::s_integrate(float t)
{
}

void Practica5::s_keyPress(unsigned char key)
{
}




