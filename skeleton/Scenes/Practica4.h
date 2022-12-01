#pragma once

#include "Scene.h"
#include "../Forces/ParticleForzeRegistry.h"

#include <list>

class GravityForceGenerator;
class WindForceGenerator;
class QuayFoceGenerator;
class FlotationForceGenerator;
class ParticleBungeeForceGenerator;
class Particle;

class Practica4 : public Scene
{

public:
	Practica4() : Scene() {};
	~Practica4() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;
	virtual void s_keyPress(unsigned char key) override;

protected:

	std::list<Particle*> particles;

	float K;
	std::list<QuayFoceGenerator*> slink;
	GravityForceGenerator* gravity;
	WindForceGenerator* wind;
	ParticleForzeRegistry forces;
};

class Practica4_2 : public Scene
{

	Particle* pa;

public:
	Practica4_2() : Scene() {};
	~Practica4_2() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;
	virtual void s_keyPress(unsigned char key) override {};

protected:



	GravityForceGenerator* gravity;
	FlotationForceGenerator* flotation;
	ParticleForzeRegistry forces;
};



class Practica4_3 : public Scene
{

	

public:
	Practica4_3() : Scene() {};
	~Practica4_3() = default;

	virtual void s_init() override;
	virtual void s_clean() override;
	virtual void s_integrate(float t) override;
	virtual void s_keyPress(unsigned char key) override;

protected:

	Particle* p1;
	Particle* p2;

	ParticleBungeeForceGenerator* goma1;
	ParticleBungeeForceGenerator* goma2;
	ParticleForzeRegistry forces;

	GravityForceGenerator* gravity;
};

