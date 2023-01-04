#include "PxWindFG.h"

PxWindFG::PxWindFG(const Vector3& vel, const Vector3& pos, double area) :
	windVel(vel), windPos(pos), radius(area), k1(0.003), k2(0.001)
{
	windArea = new RenderItem(CreateShape(physx::PxSphereGeometry(area)), new physx::PxTransform(pos.x, pos.y, pos.z), { 0, 0, 1, 0 });
}

PxWindFG::~PxWindFG()
{
	delete windArea;
}

void PxWindFG::updateForce(PxParticle* particle, double dt)
{
	if (fabs(particle->particle->getInvMass()) < 1e-10)
		return;

	if ((particle->particle->getGlobalPose().p - windPos).magnitudeSquared() > radius * radius) {
		return;
	}

	Vector3 v = windVel - particle->particle->getLinearVelocity();
	particle->particle->addForce(k1 * v + k2 * v.magnitude() * v);
}
