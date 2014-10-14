#ifndef TARGET_H
#define TARGET_H

class Target
{
public:
	Target(Ogre::SceneManager* sceneMgr);
	
	~Target(void);

	Ogre::Entity* getEntity();


private:
	Ogre::Entity* baseObj;
	Ogre::SceneNode* mNode;
};

#endif