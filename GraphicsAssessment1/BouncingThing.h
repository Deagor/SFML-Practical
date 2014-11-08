#ifndef BOUNCINGTHING_H
#define BOUNCINGTHING_H

class BouncingThing
{

public:

#pragma region Properties
	float getRotationAmount(){ return rotationAmount; }
	void setRotationAmount(float newRotation){ rotationAmount = newRotation; }
	sf::Vector2f getVelocity(){ return mVelocity; }
	void setVelocity(sf::Vector2f vel){ mVelocity = vel; }
	sf::Vector2f getPosition(){ return mPosition; }
	void setPosition(sf::Vector2f pos){ mPosition = pos; }
	sf::ConvexShape getShape(){ return shape; }
	sf::FloatRect getBoundingBox(){ return mBoundingBox; }
#pragma endregion


	virtual void Move();
	virtual void CheckBounds();

	void Draw(sf::RenderWindow* wind);

protected:
	sf::ConvexShape shape;
	float rotationAmount;
	sf::Transform rotationTransform;
	sf::FloatRect mBoundingBox;
	sf::Vector2f mVelocity;
	sf::Vector2f mPosition;
};

#endif


