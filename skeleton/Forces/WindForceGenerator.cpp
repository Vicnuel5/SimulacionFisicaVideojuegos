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

void WindForceGenerator::updateForce(Particle* particle, double t)
{
	if (fabs(particle->getInvMass()) < 1e-10)
		return;

	if ((particle->getPos() - windPos).magnitudeSquared() > radius * radius) {
		return;
	}


	//double k1 = 0.003, k2 = 0.001;
	Vector3 v = getVel(particle->getPos()) - particle->getVel();
	particle->addForce(_k1 * v + _k2 * v.magnitude() * v);
}

Vector3 WindForceGenerator::getVel(Vector3 pPos) {
	return windVel;
}
