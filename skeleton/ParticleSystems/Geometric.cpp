#include "Geometric.h"

#include "../Particles/Particle.h"

#include <math.h> 

#define PI 3.14159265

Geometric::Geometric(Vector3 std_dev_pos, float vel, int generations, int maxGenerations, int shape) :
	ParticleGenerator(), std_dev_pos(std_dev_pos), vel(vel), cont(0),
		generations(generations), maxGenerations(maxGenerations), shape(shape)
{
	particles = generateParticles();
}

void Geometric::p_Integrate(double t)
{
	cont += t;

	if (cont >= SPAWN_TIME) {

		if (generations < maxGenerations) {
			for (auto i : particles) {
				if (generations < maxGenerations) {
					Geometric* f = new Geometric(i->getPos(), vel, generations + 1, maxGenerations, shape);
					particle_generators.push_back(f);
				}
			}
		}

		for (auto i : particles) {
			delete i;
		}

		particles.clear();	
	}
}

void Geometric::p_Refresh()
{
	for (auto p = particles.begin(); p != particles.end(); ) {
		if ((*p)->getPos().y < 0) {
			auto aux = p;
			p++;
			delete* aux;
			particles.erase(aux);
		}
		else p++;
	}
}


std::list<Particle*> Geometric::generateParticles() {

	std::list<Particle*> l = std::list<Particle*>();

	Vector4 coulour = { d(gen), d(gen), d(gen), 1 };

	if (generations == 0) {
		Particle* p = new Particle(std_dev_pos, {0, vel, 0}, {0, 0, 0}, 0.95, 0.5);
		
		l.push_back(p);
	}
	else
	{
		double angle = 0.0f;
		double incr = 360.0 / shape;

		for (int i = 0; i < shape; i++) {

			Particle* p = new Particle(std_dev_pos, { 0, 10, 0 }, { 0, 0, 0 }, 0.95, 0.5);
			p->setVel({ (float) cos(angle * PI / 180.0) * vel, (float) sin(angle * PI / 180.0) * vel, 0 });
			p->setColor(coulour);
			l.push_back(p);

			angle += incr;
		}
	}

	return l;
}


