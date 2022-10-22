#pragma once

#include "Scene.h"

#include <list>
#include <cstdint>

class Particle;

class Practica1 : public Scene
{
	enum  ProyectilType {
		PISTOL,
		ARTILLERY,
		FIREBALL,
		LASER
	};

	uint8_t pType = PISTOL;

	Particle* suelo = nullptr;
	Particle* diana = nullptr;

	std::list<Particle*> particles;	

public:
	Practica1() : Scene() {};
	~Practica1() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;
	virtual void s_keyPress(unsigned char key) override;
};

