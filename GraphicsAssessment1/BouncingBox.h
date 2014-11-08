#ifndef BOUNCINGBOX_H
#define BOUNCINGBOX_H

#include "BouncingThing.h"
#include "CollisionManager.h"

class BouncingBox : public BouncingThing
{

public:
	BouncingBox();
	~BouncingBox();
	void Move();
	void CheckBounds();

private:
	float mSpeed;

};

#endif