#include "PxAnchoredSpringFG.h"

PxAnchoredSpringFG::PxAnchoredSpringFG(PxParticle* particle, double longReposo, double k) :
	PxQuayFG(nullptr, longReposo, k)
{
	myParticle = particle;
}

PxAnchoredSpringFG::~PxAnchoredSpringFG()
{
	delete myParticle;
}
