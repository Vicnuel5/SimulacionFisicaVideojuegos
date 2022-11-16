#pragma once

#include "Scene.h"

#include "../Forces/ParticleForzeRegistry.h"
#include "../ParticleSystems/Fuente.h"

#include <list>

class Particle;
class GravityForceGenerator;
class ExplosionForceGenerator;
class WhirlwindForceGenerator;

class Practica3 : public Scene
{
	GravityForceGenerator* gravity;
	std::list<Particle*> particles;

public:
	Practica3() : Scene() {};
	~Practica3() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;
	virtual void s_keyPress(unsigned char key) override {};

protected:
	ParticleForzeRegistry forces;
};

class Practica3_2 : public Practica3
{

public:
	Practica3_2() : Practica3() {};
	~Practica3_2() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;

protected:
	Fuente* fuente;

};

class Practica3_3 : public Scene
{
	GravityForceGenerator* gravity;
	WhirlwindForceGenerator* torbellino;
	ParticleForzeRegistry forces;

	std::list<Particle*> particles;

public:
	Practica3_3() : Scene() {};
	~Practica3_3() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;
	virtual void s_keyPress(unsigned char key) override {};
};

class Practica3_4 : public Scene
{
	ExplosionForceGenerator* explosion;
	ParticleForzeRegistry forces;

	std::list<Particle*> particles;

public:
	Practica3_4() : Scene() {};
	~Practica3_4() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;
	virtual void s_keyPress(unsigned char key) override;
};






