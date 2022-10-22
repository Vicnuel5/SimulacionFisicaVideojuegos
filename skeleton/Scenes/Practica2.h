#pragma once

#include "Scene.h"

#include <list>

class ParticleGenerator;
class Particle;

class Practica2 : public Scene
{

protected:

	std::list<ParticleGenerator*> particleSystems;

public:
	Practica2() : Scene() {};
	~Practica2() = default;

	virtual void s_init() = 0;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;
	virtual void s_keyPress(unsigned char key) override {};
};

class Practica2_1 : public Practica2
{

public:
	Practica2_1() : Practica2() {};
	~Practica2_1() = default;

	virtual void s_init() override;
};

class Practica2_2 : public Practica2
{
	Particle* suelo = nullptr;

public:
	Practica2_2() : Practica2() {};
	~Practica2_2() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_keyPress(unsigned char key) override;
};

class Practica2_3 : public Practica2
{

public:
	Practica2_3() : Practica2() {};
	~Practica2_3() = default;

	virtual void s_init() override;
};

