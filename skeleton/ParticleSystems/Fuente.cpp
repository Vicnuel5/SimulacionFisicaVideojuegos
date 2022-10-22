#include "Fuente.h"

#include "../Particles/Particle.h"

Fuente::Fuente(Vector3 std_dev_pos, Vector3 std_dev_vel, Vector3 std_dev_acc) :
	ParticleGenerator(), cont(0), std_dev_pos(std_dev_pos), std_dev_vel(std_dev_vel), std_dev_acc(std_dev_acc)
{
}

void Fuente::p_Integrate(double t)
{
	cont += t;

	if (cont >= SPAWN_TIME) {
	
		Particle* p = new Particle({ 0,0,0 }, std_dev_vel, std_dev_acc, 0.95, 0.5);

		p->setVel({ 0, std_dev_vel.y + dVelY(gen), 0});
		p->setPos({ dPos(gen), 0, dPos(gen) });
		p->setColor({ 0, 0, 1, 1 });
		
		particles.push_back(p);

		cont = 0;
	}
}

void Fuente::p_Refresh()
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


