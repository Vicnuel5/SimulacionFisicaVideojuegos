#pragma once

#include "ParticleGenerator.h"

#include <random>

class Geometric : public ParticleGenerator
{
	double cont;
	const double SPAWN_TIME = 2;	

	Vector3 std_dev_pos;
	float vel;

	int generations;
	int maxGenerations;

	int shape;

public:
	Geometric(Vector3 std_dev_pos, float vel, int generations, int maxGenerations, int shape);
	~Geometric() = default;

protected:
	
	std::uniform_real_distribution<float> d{ 0, 1 };

	virtual std::list<Particle*> generateParticles() override;

	void p_Integrate(double t) override;
	void p_Refresh() override;
};

