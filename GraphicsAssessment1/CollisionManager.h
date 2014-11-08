#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "BouncingThing.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	static bool checkCollisionsSAT(BouncingThing& object1, BouncingThing& object2);
	
	static sf::Vector2f Normalize(sf::Vector2f vect);

	static float dot(sf::Vector2f f, sf::Vector2f s);

private:
	static void handleCollision(BouncingThing& object1, BouncingThing& object2);
};
#endif 


