#include "Practica1.h"

#include "../Particles/Particle.h"


void Practica1::s_init()
{
	suelo = new Particle({ 0, 0, 0 }, CreateShape(physx::PxBoxGeometry(300, 1, 300)));
	suelo->setColor({ 0.5, 0.5, 0, 1 });
	diana = new Particle({ -10, 30, -10 }, CreateShape(physx::PxSphereGeometry(10)));
	diana->setColor({ 1, 0, 0, 1 });
}

void Practica1::s_clean()
{
	for (auto p : particles)
		delete p;

	delete suelo;
	delete diana;
}

void Practica1::s_integrate(float t)
{
	for (auto p : particles)
		p->integrate(t);

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

void Practica1::s_keyPress(unsigned char key)
{
	switch (key)
	{
	case 'Q': {
		Vector3 eye = GetCamera()->getEye();
		Vector3 dir = GetCamera()->getDir();
		Particle* p = new Particle(eye);
		particles.push_back(p);
		switch (pType)
		{
		case PISTOL:
			p->setMass(0.2f);
			p->setVel(dir * 35);
			p->setAcc({ 0, -1.0f, 0 });
			p->setDump(0.99f);
			p->setColor({ 0.2, 0.2, 0.2, 1 });
			break;
		case ARTILLERY:
			p->setMass(200.0f);
			p->setVel(dir * 30);
			p->setAcc({ 0, -20.0f, 0 });
			p->setDump(0.99f);
			p->setColor({ 0, 0, 0, 1 });
			break;
		case FIREBALL:
			p->setMass(1.0f);
			p->setVel(dir * 10);
			p->setAcc({ 0, 0.6f, 0 });
			p->setDump(0.9f);
			p->setColor({ 1, 0, 0, 1 });
			break;
		case LASER:
			p->setMass(0.1f);
			p->setVel(dir * 100);
			p->setDump(0.99f);
			p->setColor({ 0, 0, 1, 1 });
			break;
		}
		break;
	}
	case 'Z':
		pType = PISTOL;
		break;
	case 'X':
		pType = ARTILLERY;
		break;
	case 'C':
		pType = FIREBALL;
		break;
	case 'V':
		pType = LASER;
		break;
	}
}
