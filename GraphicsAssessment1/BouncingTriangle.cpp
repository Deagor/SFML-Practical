#include "stdafx.h"
#include "BouncingTriangle.h"


BouncingTriangle::BouncingTriangle()
{
	
	velocityX = (rand() % 20 - 10);
	velocityY = (rand() % 20 - 10);

	shape.setPointCount(3);

	mPosition.x = rand() % 700 + 50;
	mPosition.y = rand() % 500 + 50;

	sf::Vector2f p1 = rotationTransform * sf::Vector2f(cos(DTR * 90) * TRIANGLE_SIZE, sin(DTR * 90) * TRIANGLE_SIZE);
	sf::Vector2f p2 = rotationTransform * sf::Vector2f(cos(DTR * 210) * TRIANGLE_SIZE, sin(DTR * 210) * TRIANGLE_SIZE);
	sf::Vector2f p3 = rotationTransform * sf::Vector2f(cos(DTR * 330) * TRIANGLE_SIZE, sin(DTR * 330) * TRIANGLE_SIZE);

	shape.setPoint(0, mPosition + p1);
	shape.setPoint(1, mPosition + p2);
	shape.setPoint(2, mPosition + p3);

	setRotationAmount(5);

	shape.setFillColor(sf::Color::Green);
}

BouncingTriangle::~BouncingTriangle()
{
}


void BouncingTriangle::Move()
{
	rotationTransform.rotate(rotationAmount);
	mPosition.x += velocityX;
	mPosition.y += velocityY;

	sf::Vector2f p1 = rotationTransform * sf::Vector2f(cos(DTR * 90) * TRIANGLE_SIZE, sin(DTR * 90) * TRIANGLE_SIZE);
	sf::Vector2f p2 = rotationTransform * sf::Vector2f(cos(DTR * 210) * TRIANGLE_SIZE, sin(DTR * 210) * TRIANGLE_SIZE);
	sf::Vector2f p3 = rotationTransform * sf::Vector2f(cos(DTR * 330) * TRIANGLE_SIZE, sin(DTR * 330) * TRIANGLE_SIZE);

	shape.setPoint(0, mPosition + p1);
	shape.setPoint(1, mPosition + p2);
	shape.setPoint(2, mPosition + p3);

	CheckBounds();
	
}

void BouncingTriangle::CheckBounds()
{
	if (shape.getPoint(0).x <= 0 || shape.getPoint(0).x >= 800
		|| shape.getPoint(1).x <= 0 || shape.getPoint(1).x >= 800
		|| shape.getPoint(2).x <= 0 || shape.getPoint(2).x >= 800)
	{
		velocityX *= -1;
	}
	if (shape.getPoint(0).y <= 0 || shape.getPoint(0).y >= 600
		|| shape.getPoint(1).y <= 0 || shape.getPoint(1).y >= 600
		|| shape.getPoint(2).y <= 0 || shape.getPoint(2).y >= 600)
	{
		//velocityY *= -1;
	}
}