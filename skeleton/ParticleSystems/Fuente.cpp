#include "Fuente.h"

#include "../Particles/Particle.h"


Fuente::Fuente(Vector3 std_dev_pos, Vector3 std_dev_vel, Vector3 std_dev_acc) :
	ParticleGenerator(), std_dev_pos(std_dev_pos), std_dev_vel(std_dev_vel), std_dev_acc(std_dev_acc), cont(SPAWN_TIME)
{
	//particles = generateParticles();
}

std::list<Particle*> Fuente::generateParticles()
{
	std::list<Particle*> l = std::list<Particle*>();

	std::random_device rd{};
	std::mt19937 gen{ rd() };

	for (int i = 0; i < 30; i++) {
		double rnd = d(gen);
		Particle* p = new Particle(std_dev_pos * rnd, std_dev_vel * rnd, std_dev_acc, 0.95, 0.5);
		p->setColor({0, 0, 1, 1});
		l.push_back(p);
	}

	return l;
}

void Fuente::pIntegrate(double t)
{
	cont += t;

	if (t >= SPAWN_TIME) {
		std::random_device rd{};
		std::mt19937 gen{ rd() };
		double rnd = d(gen);
		Particle* p = new Particle(std_dev_pos * rnd, std_dev_vel * rnd, std_dev_acc, 0.95, 0.5);

		particles.push_back(p);

		cont = 0;
	}
}


