#include "DragGenerator.h"

DragGenerator::DragGenerator(const float k1, const float k2) :
	_k1(k1), _k2(k2)
{
}

void DragGenerator::updateForce(Particle* particle, float t)
{
	if (fabs(particle->getInvMass()) < 1e-10)
		return;

	Vector3 v = particle->getVel();
	float drag_coef = v.normalize();
	drag_coef = _k1 * drag_coef + _k2 * drag_coef * drag_coef;
	Vector3 dragF = -v * drag_coef;
	particle->addForce(dragF);
}
