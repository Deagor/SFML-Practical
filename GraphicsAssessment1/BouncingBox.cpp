#include "stdafx.h"
#include "BouncingBox.h"


BouncingBox::BouncingBox() : mSpeed(2)
{
	
	float velocityX = (rand() % 20 - 10);
	float velocityY = (rand() % 20 - 10);
	mVelocity = sf::Vector2f(velocityX, velocityY);
	mVelocity = CollisionManager::Normalize(mVelocity);
	shape.setPointCount(4);

	mPosition.x = rand() % 700 + 50;
	mPosition.y = rand() % 500 + 50;

	sf::Vector2f p1 = rotationTransform * sf::Vector2f(cos(DTR * 45) * RECTANGLE_SIZE, sin(DTR * 45) * RECTANGLE_SIZE);
	sf::Vector2f p2 = rotationTransform * sf::Vector2f(cos(DTR * 135) * RECTANGLE_SIZE, sin(DTR * 135) * RECTANGLE_SIZE);
	sf::Vector2f p3 = rotationTransform * sf::Vector2f(cos(DTR * 225) * RECTANGLE_SIZE, sin(DTR * 225) * RECTANGLE_SIZE);
	sf::Vector2f p4 = rotationTransform * sf::Vector2f(cos(DTR * 315) * RECTANGLE_SIZE, sin(DTR * 315) * RECTANGLE_SIZE);

	shape.setPoint(0, mPosition + p1);
	shape.setPoint(1, mPosition + p2);
	shape.setPoint(2, mPosition + p3);
	shape.setPoint(3, mPosition + p4);
	
	mBoundingBox = shape.getGlobalBounds();

	setRotationAmount(5);

	shape.setFillColor(sf::Color::Blue);
}

BouncingBox::~BouncingBox()
{
}


void BouncingBox::Move()
{
	rotationTransform.rotate(rotationAmount);
	mPosition += mVelocity;

	sf::Vector2f p1 = rotationTransform * sf::Vector2f(cos(DTR * 45) * RECTANGLE_SIZE, sin(DTR * 45) * RECTANGLE_SIZE);
	sf::Vector2f p2 = rotationTransform * sf::Vector2f(cos(DTR * 135) * RECTANGLE_SIZE, sin(DTR * 135) * RECTANGLE_SIZE);
	sf::Vector2f p3 = rotationTransform * sf::Vector2f(cos(DTR * 225) * RECTANGLE_SIZE, sin(DTR * 225) * RECTANGLE_SIZE);
	sf::Vector2f p4 = rotationTransform * sf::Vector2f(cos(DTR * 315) * RECTANGLE_SIZE, sin(DTR * 315) * RECTANGLE_SIZE);

	shape.setPoint(0, mPosition + p1);
	shape.setPoint(1, mPosition + p2);
	shape.setPoint(2, mPosition + p3);
	shape.setPoint(3, mPosition + p4);
	mBoundingBox = shape.getGlobalBounds();
	CheckBounds();

}

void BouncingBox::CheckBounds()
{
	if (shape.getPoint(0).x <= 0 || shape.getPoint(0).x >= 800
		|| shape.getPoint(1).x <= 0 || shape.getPoint(1).x >= 800
		|| shape.getPoint(2).x <= 0 || shape.getPoint(2).x >= 800
		|| shape.getPoint(3).x <= 0 || shape.getPoint(3).x >= 800)
	{
		mVelocity.x *= -1;
	}
	if (shape.getPoint(0).y <= 0 || shape.getPoint(0).y >= 600
		|| shape.getPoint(1).y <= 0 || shape.getPoint(1).y >= 600
		|| shape.getPoint(2).y <= 0 || shape.getPoint(2).y >= 600
		|| shape.getPoint(3).y <= 0 || shape.getPoint(3).y >= 600)
	{
		mVelocity.y *= -1;
	}
}
