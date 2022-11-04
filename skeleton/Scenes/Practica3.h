#pragma once

#include "Scene.h"

#include "../Forces/ParticleForzeRegistry.h"

#include <list>

class Particle;

class Practica3 : public Scene
{

	std::list<Particle*> particles;
	ParticleForzeRegistry forces;

	Particle* suelo = nullptr;

public:
	Practica3() : Scene() {};
	~Practica3() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;
	virtual void s_keyPress(unsigned char key) override;
};

