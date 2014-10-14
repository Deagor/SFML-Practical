#include "stdafx.h"
#include "Missile.h"


#pragma region Properties

Ogre::SceneNode* Missile::getNode()
{
	return mNode;
}

Ogre::Vector3 Missile::getPosition()
{
	return mNode->getPosition();
}

Ogre::Vector3 Missile::getVelocity()
{
	return mVelocity;
}

Ogre::Entity* Missile::getEntity(){return missile;}

bool Missile::getNeedsReset() { return mNeedsReset;}

bool Missile::isAllowedMove()
{
	return mAllowedMove;
}

void Missile::setPosition(Ogre::Vector3 newPos)
{
	mNode->setPosition(newPos);
}

void Missile::setVelocity(Ogre::Vector3 newVelo)
{
	mVelocity = newVelo;
}  

void Missile::setNeedsReset(bool reset){mNeedsReset = reset;}

#pragma endregion



Missile::Missile(Ogre::SceneManager* mSceneMgr,float cubeLength,double cylLength,Cannon* myCannon) : mAllowedMove(false), mNeedsReset(false)
{
	static int NUM_MISSILES_CREATED = 0;
	//Create missile and it's node
	missile = mSceneMgr->createEntity("Missile", "Sphere.mesh");

	missile->setMaterialName("Examples/Chrome");  
	mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode( "MissileNode" + NUM_MISSILES_CREATED,Ogre::Vector3::Vector3(100,0,0) );
	mNode->attachObject( missile );
	missile->setCastShadows(true);
	double missileScale = 0.003;
	mNode->scale(missileScale,missileScale,missileScale);
	mNode->setPosition(Ogre::Vector3(0, cubeLength, 0)+ cylLength*(myCannon->getOrientation()*(Ogre::Vector3::UNIT_Y)));

	NUM_MISSILES_CREATED++;
}

Missile::~Missile(void)
{

}

void Missile::Update(double timeSinceLastFrame)
{
	if(mAllowedMove)
	{
		mVelocity += (mGravEffect * timeSinceLastFrame);
		Ogre::Vector3 currentPos = mNode->getPosition();
		mNode->setPosition(currentPos + (mVelocity * timeSinceLastFrame));
	}
}

void Missile::Reset(Cannon* myCannon)
{
	mNode->setPosition(Ogre::Vector3(0, myCannon->getBaseCubeLength(), 0)+ myCannon->getLengthBarrel()*(myCannon->getOrientation()*(Ogre::Vector3::UNIT_Y)));
}

void Missile::SetMove(bool setTo)
{
	mAllowedMove = setTo;
}

void Missile::SetGravEffect(float effect)
{
	mGravEffect = Ogre::Vector3(0,effect,0);
}

void Missile::SetSpeed(float speed)
{
	mSpeed = speed;
}