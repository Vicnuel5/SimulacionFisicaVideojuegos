#pragma once

#include "ParticleGenerator.h"
#include <random>

class Fuente : public ParticleGenerator
{

	double cont;
	const double SPAWN_TIME = 0.3;

public:
	Fuente(Vector3 std_dev_pos, Vector3 std_dev_vel, Vector3 std_dev_acc);
	~Fuente() = default;

	virtual std::list<Particle*> generateParticles() override;

protected:
	Vector3 std_dev_pos, 
		std_dev_vel,
		std_dev_acc;

	std::normal_distribution<double> d{ 1, 0.5 };

	void pIntegrate(double t) override;
};

