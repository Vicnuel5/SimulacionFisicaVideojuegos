#include "Practica3.h"

#include "../Forces/GravityForceGenerator.h"

void Practica3::s_init()
{
	Particle* p = new Particle({ 0, 50, 0 });
	p->setMass(5);

	Particle* p2 = new Particle({ 10, 50, 0 });
	p2->setMass(20);

	forces.addRegistry(new GravityForceGenerator({ 0, -2, 0 }), p);
	forces.addRegistry(new GravityForceGenerator({ 0, -2, 0 }), p2);
	particles.push_back(p);
	particles.push_back(p2);
}

void Practica3::s_clean()
{
	for (auto p : particles)
		delete p;

	particles.clear();
}

void Practica3::s_integrate(float t)
{
	forces.updteForces(0);

	for (auto i : particles)
		i->integrate(t);
}

void Practica3::s_keyPress(unsigned char key)
{
}
