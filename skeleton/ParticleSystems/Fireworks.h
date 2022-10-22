#pragma once

#include "ParticleGenerator.h"

#include <random>

class Fireworks : public ParticleGenerator
{
	double cont;
	double blowTime = 2;
	bool exploded;

public:
	Fireworks(Vector3 std_dev_pos, Vector3 std_dev_vel);
	~Fireworks() = default;

protected:
	Vector3 std_dev_pos, std_dev_vel;
	Vector4 coulour;

	std::uniform_real_distribution<float> blowTimeD{ 1.5, 3 };
	std::uniform_real_distribution<float> colD{ 0, 1 };
	std::normal_distribution<float> dVelY{ 15, 5 };
	std::normal_distribution<float> dVelXY{ 0, 1 };

	virtual std::list<Particle*> generateParticles() override;

	void p_Integrate(double t) override;
	void p_Refresh() override;
};