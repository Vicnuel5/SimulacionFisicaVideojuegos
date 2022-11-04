#include "Practica2.h"

#include "../ParticleSystems/ParticleGenerator.h"
#include "../ParticleSystems/Fireworks.h"
#include "../ParticleSystems/Fuente.h"
#include "../ParticleSystems/Geometric.h"

#include "../Particles/Particle.h"

#include <random>

void Practica2::s_clean()
{
	for (auto i : particleSystems)
		delete i;

	particleSystems.clear();
}

void Practica2::s_integrate(float t)
{
	for (auto i : particleSystems)
		i->integrate(t);
}

void Practica2_1::s_init()
{
	particleSystems.push_back(new Fuente({ 0, 0, 0 }, { 0, 30, 0 }, { 0, -9.8, 0 }));
}

void Practica2_2::s_init()
{
	suelo = new Particle({ 0, 0, 0 }, CreateShape(physx::PxBoxGeometry(50, 1, 50)));
	suelo->setColor({ 0.5, 0.5, 0, 1 });
}

void Practica2_2::s_clean()
{
	Practica2::s_clean();

	delete suelo;
}

void Practica2_2::s_keyPress(unsigned char key)
{
	switch (key)
	{
	case 'Q':
		particleSystems.push_back(new Fireworks({ rand() % 51 - 25.0f, 0, rand() % 51 - 25.0f }, {5, 50, 5}));
		break;
	}
}

void Practica2_3::s_init()
{
	particleSystems.push_back(new Geometric({ 0,20,0 }, 10, 0, 3, 10));
}
