#include "Fireworks.h"

#include "../Particles/Particle.h"


Fireworks::Fireworks(Vector3 std_dev_pos, Vector3 std_dev_vel) :
	std_dev_pos(std_dev_pos), std_dev_vel(std_dev_vel), cont(0), exploded(false) {

	coulour = { colD(gen), colD(gen), colD(gen), 1 };

	Particle* p = new Particle(std_dev_pos, { 0, std_dev_vel.y, 0 }, { 0, 0, 0 }, 0.95, 0.5);
	p->setColor(coulour);
	particles.push_back(p);

	blowTime = blowTimeD(gen);

	
}

void Fireworks::p_Integrate(double t)
{
	cont += t;

	if (cont >= blowTime && !exploded) {

		auto p = (*particles.begin());
		std_dev_pos = p->getPos();
		delete p;

		particles.clear();

		particles = generateParticles();

		exploded = true;
	}
}

void Fireworks::p_Refresh() {
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

std::list<Particle*> Fireworks::generateParticles() {

	std::list<Particle*> l = std::list<Particle*>();

	 


	for (int i = 0; i < 100; i++) {

		Particle* p = new Particle(std_dev_pos);
		p->setVel({ std_dev_vel.x * dVelXY(gen), dVelY(gen), std_dev_vel.z * dVelXY(gen) });
		p->setAcc({ 0, -20, 0 });
		p->setMass(1);
		p->setDump(0.95);
		p->setColor(coulour);
		l.push_back(p);
	}

	return l;
}
