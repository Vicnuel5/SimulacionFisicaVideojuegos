#include "Practica4.h"

#include "../Particles/Particle.h"

#include "../Forces/GravityForceGenerator.h"
#include "../Forces/QuayFoceGenerator.h"
#include "../Forces/AnchoredSpringForceGenerator.h"
#include "../Forces/WindforceGenerator.h"
#include "../Forces/FlotationForceGenerator.h"
#include "../Forces/ParticleBungeeForceGenerator.h"
#include <iostream>


void Practica4::s_init()
{
	wind = nullptr;

	K = 100;
	const double lon = 5;
	float h = 70;

	Particle* p = new Particle({ 0, h - 10, 0 });
	p->setMass(10);
	p->setDump(0.8);

	gravity = new GravityForceGenerator({ 0, -9.8, 0 });
	forces.addRegistry(gravity, p);
	auto f = new AnchoredSpringForceGenerator({ 0, h, 0 }, lon, K);
	forces.addRegistry(f, p);
	slink.push_back(f);
	particles.push_back(p);

	int n = 4;
	h -= 20;
	for (int i = 0; i < n; i++) {
		Particle* p2 = new Particle({ 0, h, 0 });
		p2->setMass(10);
		p2->setDump(0.8);
		h -= 10;

		forces.addRegistry(gravity, p2);

		auto muelle = new QuayFoceGenerator(p, lon, K);
		forces.addRegistry(muelle, p2);
		slink.push_back(muelle);
		muelle = new QuayFoceGenerator(p2, lon, K);
		forces.addRegistry(muelle, p);	
		slink.push_back(muelle);
		particles.push_back(p2);

		p = p2;
	}
}

void Practica4::s_clean()
{
	delete gravity;

	delete wind;

	for (auto it : slink) {
		delete it;
	}

	for (auto i : particles)
		delete i;
}

void Practica4::s_integrate(float t)
{
	forces.updteForces(0);

	for (auto i : particles)
		i->integrate(t);
}

void Practica4::s_keyPress(unsigned char key)
{
	switch (key)
	{
	case 'Q':
		K -= 1;
		std::cout << K << std::endl;
		for (auto f : slink)
			f->setK(K);
		break;
	case 'E':
		K += 1;
		std::cout << K << std::endl;
		for (auto f : slink)
			f->setK(K);
		break;
	case 'Z':
		if (wind == nullptr) {
			wind = new WindForceGenerator({ 200, 0, -200 }, { 0, 40, 0 }, 20);
			for (auto p : particles)
				forces.addRegistry(wind, p);
		}
		else {		
			forces.deleteForceRegistry(wind);
			delete wind;
			wind = nullptr;
		}
	}
	
}

void Practica4_2::s_init()
{
	Vector3 dimension = Vector3(2, 2, 2);
	pa = new Particle({ 0, 0, 0 }, CreateShape(physx::PxBoxGeometry(dimension)));
	pa->setColor({ 0.5, 0.5, 0, 1 });
	
	pa->setMass(7);
	pa->setDump(0.95);

	flotation = new FlotationForceGenerator({ 0, 0, 0 }, dimension);
	gravity = new GravityForceGenerator({ 0, -9.8, 0 });
	forces.addRegistry(gravity, pa);
	forces.addRegistry(flotation, pa);
}

void Practica4_2::s_clean()
{
	delete pa;

	delete flotation;
	delete gravity;
}

void Practica4_2::s_integrate(float t)
{
	forces.updteForces(0);

	pa->integrate(t);
}

void Practica4_3::s_init()
{
	p1 = new Particle({ 0,0, 0 });
	p1->setMass(5);
	p1->setDump(0.8);
	p1->setColor({ 1,1,0, 1 });

	p2 = new Particle({ 15, 0 , 0 });
	p2->setMass(5);
	p2->setDump(0.8);

	goma1 = new ParticleBungeeForceGenerator(p1, 10, 5);
	forces.addRegistry(goma1, p2);
	goma2 = new ParticleBungeeForceGenerator(p2, 10, 5);
	forces.addRegistry(goma2, p1);


	gravity = nullptr;
}

void Practica4_3::s_clean()
{
	delete goma1;
	delete goma2;

	delete p1;
	delete p2;
}

void Practica4_3::s_integrate(float t)
{
	forces.updteForces(0);

	p1->integrate(t);
	p2->integrate(t);
}

void Practica4_3::s_keyPress(unsigned char key)
{
	switch (key)
	{
	case 'Z':
		if (gravity == nullptr) {
			gravity = new GravityForceGenerator({ 0, -9.8, 0 });
			forces.addRegistry(gravity, p1);
		}
		else {
			forces.deleteForceRegistry(gravity);
			delete gravity;
			gravity = nullptr;
		}
	}
}
