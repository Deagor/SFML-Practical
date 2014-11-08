#include "stdafx.h"
#include "Target.h"


#pragma region Properties

Ogre::Entity* Target::getEntity(){ return baseObj;}

#pragma endregion


Target::Target(Ogre::SceneManager* sceneMgr)
{
	baseObj = sceneMgr->createEntity("cube2","cube.mesh");
	baseObj->setMaterialName("Examples/RustySteel");
	mNode = sceneMgr->createSceneNode("cube2Node");
	sceneMgr->getRootSceneNode()->addChild(mNode);
	mNode->attachObject(baseObj);
	baseObj->setCastShadows(true);
	float cubeModelLength = 100;
	float cubeLength = 4;

	double cubeScale = cubeLength / cubeModelLength;
	mNode->scale(cubeScale,cubeScale,cubeScale);
	//position it on the ground
	
	mNode->setPosition(Ogre::Vector3((rand() % 40) + 20,cubeLength/2,(rand() % 80) - 40));
}


Target::~Target(void)
{

}
