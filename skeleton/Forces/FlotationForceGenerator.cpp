#include "FlotationForceGenerator.h"

FlotationForceGenerator::FlotationForceGenerator(Vector3 pos, Vector3 otherDimension) :
	otherVolume(otherDimension.x * otherDimension.y * otherDimension.z), otherHeight(otherDimension.y)
{
	water = new Particle({ pos }, CreateShape(physx::PxBoxGeometry(10, 0.1, 10)));
	water->setColor({ 0,0,1,1 });
}

void FlotationForceGenerator::updateForce(Particle* p, double t)
{
	float immersed;

	if (p->getPos().y - water->getPos().y > otherHeight * 0.5) {
		immersed = 0.0; }
	else if (water->getPos().y - p->getPos().y > otherHeight * 0.5) {
		immersed = 1.0; }
	else {
		immersed = (water->getPos().y - p->getPos().y) / otherHeight + 0.5;
	}

	p->addForce(Vector3(0, 1 * otherVolume * immersed * 9.8, 0));
}

FlotationForceGenerator::~FlotationForceGenerator()
{
	delete water;
}
