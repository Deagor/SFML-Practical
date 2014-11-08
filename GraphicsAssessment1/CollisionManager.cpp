#include "stdafx.h"
#include "CollisionManager.h"


CollisionManager::CollisionManager()
{

}


bool CollisionManager::checkCollisionsSAT(BouncingThing& object1, BouncingThing& object2)
{
	sf::Vector2f normalToCheck, edge;
	std::vector<sf::Vector2f> shape1Edges, shape2Edges;
	float dotAns;
	sf::ConvexShape obj1Shape = object1.getShape();
	sf::ConvexShape obj2Shape = object2.getShape();

#pragma region MakeEdges
	for (int i = 0; i < obj1Shape.getPointCount(); i++)
	{
		edge = obj1Shape.getPoint(i) - obj1Shape.getPoint((i + 1) % obj1Shape.getPointCount());
		edge = sf::Vector2f(-edge.y, edge.x);
		edge = Normalize(edge);
		shape1Edges.push_back(edge);
	}

	for (int i = 0; i < obj2Shape.getPointCount(); i++)
	{
		edge = obj2Shape.getPoint(i) - obj2Shape.getPoint((i + 1) % obj2Shape.getPointCount());
		edge = sf::Vector2f(-edge.y, edge.x);
		edge = Normalize(edge);
		shape2Edges.push_back(edge);
	}
#pragma endregion

	for (auto i : shape1Edges)
	{
		float minFirst = FLT_MAX, maxFirst = -FLT_MAX;
		float minSecond = FLT_MAX, maxSecond = -FLT_MAX;
		for (int z = 0; z < obj1Shape.getPointCount(); z++)
		{
			dotAns = dot(obj1Shape.getPoint(z), i);

			if (dotAns < minFirst){ minFirst = dotAns; }
			if (dotAns > maxFirst){ maxFirst = dotAns; }
		}
		for (int z = 0; z < obj2Shape.getPointCount(); z++)
		{
			dotAns = dot(obj2Shape.getPoint(z), i);

			if (dotAns < minSecond){ minSecond = dotAns; }
			if (dotAns > maxSecond){ maxSecond = dotAns; }
		}
		if (minFirst > maxSecond || minSecond > maxFirst){ return false; }
	}
	for (auto i : shape2Edges)
	{
		float minFirst = FLT_MAX, maxFirst = -FLT_MAX;
		float minSecond = FLT_MAX, maxSecond = -FLT_MAX;
		for (int z = 0; z < obj1Shape.getPointCount(); z++)
		{
			dotAns = dot(obj1Shape.getPoint(z), i);
			if (dotAns < minFirst){ minFirst = dotAns; }
			if (dotAns > maxFirst){ maxFirst = dotAns; }
		}
		for (int z = 0; z < obj2Shape.getPointCount(); z++)
		{
			dotAns = dot(obj2Shape.getPoint(z), i);
			if (dotAns < minSecond){ minSecond = dotAns; }
			if (dotAns > maxSecond){ maxSecond = dotAns; }
		}
		if (minFirst > maxSecond || minSecond > maxFirst){ return false; }
	}
	handleCollision(object1,object2);
	return true;
}

CollisionManager::~CollisionManager()
{
}

sf::Vector2f CollisionManager::Normalize(sf::Vector2f vect)
{
	float length;
	length = std::sqrt((vect.x * vect.x) + (vect.y * vect.y));

	return vect / length;
}

float CollisionManager::dot(sf::Vector2f f, sf::Vector2f s)
{
	return (f.x * s.x) + (f.y * s.y);
}

void CollisionManager::handleCollision(BouncingThing& object1, BouncingThing& object2)
{
	sf::Vector2f NVect = object1.getPosition() - object2.getPosition();
	NVect = Normalize(NVect);

	sf::Vector2f exitVelocity1 = object1.getVelocity() - (2 * (dot(NVect, object1.getVelocity())) * NVect);
	sf::Vector2f exitVelocity2 = object2.getVelocity() - (2 * (dot(NVect, object2.getVelocity())) * NVect);

	object1.setVelocity(exitVelocity1);
	object2.setVelocity(exitVelocity2);
}