#ifndef BOUNCINGTRIGANLE_H
#define BOUNCINGTRIANGLE_H

#include "BouncingObject.h"

class BouncingTriangle : public BouncingObject
{
public:
	BouncingTriangle();
	~BouncingTriangle();
	void Move();
	void CheckBounds();

};

#endif