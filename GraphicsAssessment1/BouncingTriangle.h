#ifndef BOUNCINGTRIANGLE_H
#define BOUNCINGTRIANGLE_H

#include "BouncingThing.h"

class BouncingTriangle : public BouncingThing
{
public:
	BouncingTriangle();
	~BouncingTriangle();

	void Move();
	void CheckBounds();

private:
	float mSpeed;
};

#endif