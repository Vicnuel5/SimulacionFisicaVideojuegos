#include "Practica5.h"
#include "../RenderUtils.hpp"

#include "../PxForces/PxGravityFG.h"
#include "../PxForces/PxWindFG.h"

using namespace physx;

void Practica5::s_init()
{
	myScene->setGravity({ 0, 0, 0 });

	PxRigidStatic* suelo = myPhysics->createRigidStatic(PxTransform({ 0, 0, 0 }));
	PxShape* shape = CreateShape(PxBoxGeometry(100, 0.1, 100));
	suelo->attachShape(*shape);
	items.push_back(new RenderItem(shape, suelo, { 0.8, 0.8,0.8, 1 }));
	myScene->addActor(*suelo);

	PxRigidStatic* pared = myPhysics->createRigidStatic(PxTransform({ 10, 10, -30 }));
	PxShape* shape_suelo = CreateShape(PxBoxGeometry(40, 20, 5));
	pared->attachShape(*shape_suelo);
	items.push_back(new RenderItem(shape_suelo, pared, { 0.8, 0.8,0.8, 1 }));
	myScene->addActor(*pared);


	physx::PxRigidDynamic* bola = myPhysics->createRigidDynamic(PxTransform({ 0, 20, 0 }));
	PxShape* shape_bola = CreateShape(PxSphereGeometry(1));
	bola->attachShape(*shape_bola);
	bola->setLinearDamping(0.95);
	bola->setAngularDamping(0.99);
	items.push_back(new RenderItem(shape_bola, bola, { 1, 1,0, 1 }));
	myScene->addActor(*bola);


	Vector3 size(5, 5, 5);
	physx::PxRigidDynamic* cubo = myPhysics->createRigidDynamic(PxTransform({ 0, 40, -20 }));
	PxShape* shape_cubo = CreateShape(PxBoxGeometry(size));
	cubo->attachShape(*shape_cubo);
	//cubo->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y });
	items.push_back(new RenderItem(shape_cubo, cubo, { 1, 1,0, 1 }));
	myScene->addActor(*cubo);
	

	g = new PxGravityFG({ 0, -9.8, 0 });
	forces.addRegistry(g, bola);
	forces.addRegistry(g, cubo);

	w = new PxWindFG({ 100, 0, 0 }, { 0, 0, 0 }, 50);
	forces.addRegistry(w, bola);
}

void Practica5::s_clean()
{

	forces.deleteForceRegistry(g);
	forces.deleteForceRegistry(w);

	delete g;
	delete w;


	for (auto i : items) {
		DeregisterRenderItem(i);
	}

}

void Practica5::s_integrate(float t)
{
	forces.updteForces(t);
}

void Practica5::s_keyPress(unsigned char key)
{
}




