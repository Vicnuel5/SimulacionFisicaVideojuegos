#pragma once

#include "PxPickableParticle.h"
class Sarten : public PxPickableParticle
{
	float aceite;
	physx::PxVec3 tamAceite;
	physx::PxTransform* aceiteTr;
	

public:
	Sarten(physx::PxPhysics* physx, physx::PxTransform& pose);
	virtual ~Sarten();

	void echarAceite();
	void quemarAceite();
};

