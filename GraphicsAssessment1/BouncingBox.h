#ifndef BOUNCINGBOX_H
#define BOUNCINGBOX_H

#include "BouncingObject.h"

class BouncingBox : public BouncingObject
{

public:
	BouncingBox();
	~BouncingBox();
	void Move();
	void CheckBounds();

};

#endif