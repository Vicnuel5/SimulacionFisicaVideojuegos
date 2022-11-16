#pragma once

#include "ParticleGenerator.h"
#include "../Forces/WindForceGenerator.h"

class Fuente : public ParticleGenerator
{

	double cont;
	const double SPAWN_TIME = 0.001;

	std::mt19937 gen;

public:
	Fuente(Vector3 std_dev_pos, Vector3 std_dev_vel, Vector3 std_dev_acc);
	Fuente(Vector3 std_dev_pos, Vector3 std_dev_vel, Vector3 std_dev_acc, double diePos);
	~Fuente() = default;

protected:
	Vector3 std_dev_pos,
		std_dev_vel,
		std_dev_acc;

	double diePos;

	std::normal_distribution<float> dPos{ 0, 2 };
	std::normal_distribution<float> dVelY{ 0, 1 };

	void p_Integrate(double t) override;
	void p_Refresh() override;
};

