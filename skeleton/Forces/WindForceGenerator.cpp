#include "WindForceGenerator.h"

WindForceGenerator::WindForceGenerator(const Vector3& vel, const Vector3& pos, double area) :
	DragGenerator(0.003, 0.001), windVel(vel), windPos(pos), radius(area)
{

	windArea = new RenderItem(CreateShape(physx::PxSphereGeometry(area)), new physx::PxTransform(pos.x, pos.y, pos.z), { 0, 0, 1, 0 });
}

WindForceGenerator::~WindForceGenerator()
{
	DeregisterRenderItem(windArea);
}

void WindForceGenerator::updateForce(Particle* myParticle, double t)
{
	if (fabs(myParticle->getInvMass()) < 1e-10)
		return;

	if ((myParticle->getPos() - windPos).magnitudeSquared() > radius * radius) {
		return;
	}

	Vector3 v = getVel(myParticle->getPos()) - myParticle->getVel();
	myParticle->addForce(_k1 * v + _k2 * v.magnitude() * v);
}

Vector3 WindForceGenerator::getVel(Vector3 pPos) {
	return windVel;
}
