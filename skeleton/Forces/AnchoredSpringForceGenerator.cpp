#include "AnchoredSpringForceGenerator.h"

AnchoredSpringForceGenerator::AnchoredSpringForceGenerator(Vector3 Pos, double longReposo, double k) :
	QuayFoceGenerator(nullptr, longReposo, k)
{
	myParticle = new Particle(Pos, CreateShape(physx::PxBoxGeometry(3, 1, 3)));
}

AnchoredSpringForceGenerator::~AnchoredSpringForceGenerator()
{
	delete myParticle;
}
