#include "WhirlwindForceGenerator.h"

WhirlwindForceGenerator::WhirlwindForceGenerator(const Vector3& pos, double area, double k) :
  WindForceGenerator({0,0,0}, pos, area), K(k) {
}

Vector3 WhirlwindForceGenerator::getVel(Vector3 pPos) {
	return K * Vector3(-(pPos.z - windPos.z), 50 - (pPos.y - windPos.y), pPos.x - windPos.x);
}