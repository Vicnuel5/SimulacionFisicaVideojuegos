#include "Practica3.h"

#include "../Forces/GravityForceGenerator.h"
#include "../Forces/WhirlwindForceGenerator.h"
#include "../Forces/ExplosionForceGenerator.h"

void Practica3::s_init()
{
	Particle* p = new Particle({ 0, 50, 0 });
	p->setMass(5);
	Particle* p2 = new Particle({ 10, 50, 0 });
	p2->setMass(20);

	gravity = new GravityForceGenerator({ 0, -9.8, 0 });
	forces.addRegistry(gravity, p);
	forces.addRegistry(gravity, p2);
	particles.push_back(p);
	particles.push_back(p2);
}

void Practica3::s_clean()
{
	for (auto p : particles)
		delete p;

	particles.clear();

	forces.clear();

	delete gravity;
}

void Practica3::s_integrate(float t)
{
	forces.updteForces(0);

	for (auto i : particles)
		i->integrate(t);
}

void Practica3_2::s_init()
{
	fuente = new Fuente({ 0, 0, 0 }, { 0, 30, 0 }, { 0, -9.8, 0 }, -1000);
	fuente->addForce(new WindForceGenerator({ 100, 0, 100 }, { 0, 0, 0 }, 50));
	fuente->addForce(new WindForceGenerator({ 0, 250, 0 }, { 50, 50, 50 }, 50));
	fuente->addForce(new WhirlwindForceGenerator({ 150, -200, 150 }, 150, 6));
}

void Practica3_2::s_integrate(float t)
{
	fuente->integrate(t);
}

void Practica3_2::s_clean()
{
	delete fuente;
}

void Practica3_3::s_init()
{
	gravity = new GravityForceGenerator({ 0, -9.8, 0 });
	torbellino = new WhirlwindForceGenerator({ 0, 0, 0 }, 500, 1.5);

	for (float i = -50; i < 50; i += 2) {
		for (float k = -50; k < 50; k += 2) {
			Particle* p = new Particle({ i, 0, k });
			p->setMass(1);
			p->setDump(0.95);
			particles.push_back(p);
			forces.addRegistry(gravity, p);
			forces.addRegistry(torbellino, p);
		}
	}
}

void Practica3_3::s_clean()
{
	for (auto p : particles)
		delete p;

	particles.clear();

	forces.clear();

	delete gravity;
	delete torbellino;
}

void Practica3_3::s_integrate(float t)
{
	forces.updteForces(0);

	for (auto i : particles)
		i->integrate(t);
}

void Practica3_4::s_init()
{
	explosion = new ExplosionForceGenerator({ 20,0,-20 }, 40, 4000);

	for (float i = -10; i < 10; i += 2) {
		for (float j = -10; j < 10; j += 2) {
			for (float k = -10; k < 10; k += 2) {
				Particle* p = new Particle({ i, j, k });
				p->setMass(1);
				p->setDump(0.95);
				particles.push_back(p);
				forces.addRegistry(explosion, p);
			}
		}
	}
}

void Practica3_4::s_clean()
{
	for (auto p : particles)
		delete p;

	particles.clear();

	forces.clear();

	delete explosion;
}

void Practica3_4::s_integrate(float t)
{
	forces.updteForces(t);

	for (auto i : particles)
		i->integrate(t);
}

void Practica3_4::s_keyPress(unsigned char key) {
	switch (key)
	{
	case 'Q':
		explosion->resetExplsion();
		break;
	}
}

