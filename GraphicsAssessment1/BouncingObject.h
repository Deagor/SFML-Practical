#ifndef BOUNCINGOBJECT_H
#define BOUNCINGOBJECT_H

#include "stdafx.h"

class BouncingObject
{

public:

#pragma region Properties
	float getRotationAmount(){ return rotationAmount; }
	void setRotationAmount(float newRotation){ rotationAmount = newRotation; }
	float getVelocityX(){ return velocityX; }
	float getVelocityY(){ return velocityY; }
	sf::Vector2f getPosition(){ return mPosition; }
#pragma endregion

	void Draw(sf::RenderWindow* wind){ wind->draw(shape); }

	//Pure virtuals
	virtual void Move() = 0;
	virtual void CheckBounds() = 0;

protected:
	sf::ConvexShape shape;
	float rotationAmount;
	sf::Transform rotationTransform;

	float velocityX, velocityY;
	sf::Vector2f mPosition;
};

#endif


