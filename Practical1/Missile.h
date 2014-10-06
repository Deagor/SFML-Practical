#ifndef MISSILE_H
#define MISSILE_H

class Missile
{
public:

#pragma region Properties
	Ogre::SceneNode* getNode();
	Ogre::Vector3 getPosition();
	Ogre::Vector3 getVelocity();
	bool isAllowedMove();
	bool getNeedsReset();

	void setPosition(Ogre::Vector3 newPos);
	void setVelocity(Ogre::Vector3 newVelo);
	void setNeedsReset(bool reset);
#pragma endregion

	Missile(Ogre::SceneManager* mSceneMgr,float cubeLength,double cylLength,Cannon* myCannon);
	~Missile();
	void Update();
	void Reset(Cannon* myCannon);
	void ToggleMove();
	
private:
	Ogre::Vector3 mVelocity;
	Ogre::SceneNode *mNode;
	bool mAllowedMove;
	bool mNeedsReset;
};

#endif