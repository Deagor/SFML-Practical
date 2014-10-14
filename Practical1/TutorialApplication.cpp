/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
___                 __    __ _ _    _ 
/___\__ _ _ __ ___  / / /\ \ (_) | _(_)
//  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
|___/                              
Tutorial Framework
http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#include "stdafx.h"
#include "BaseApplication.h"
#include "TutorialApplication.h"


//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
	//set lighting
	mSceneMgr->setAmbientLight(Ogre::ColourValue(.5f,.5f,.5f));
	//create ground with grass
	Ogre::Plane plane;
	plane.normal = Ogre::Vector3::UNIT_Y;

	//Horizontal plane with normal up in y-direction
	plane.d = 0; //plane passes through the origin i.e y = 0

	Ogre::MeshManager::getSingleton().createPlane("floor",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		plane,1000,1000,10,10,true,1,10,10,Ogre::Vector3::UNIT_Z);

	Ogre::Entity* pPlaneEnt = mSceneMgr->createEntity("plane","floor");
	pPlaneEnt->setMaterialName("Examples/GrassFloor");
	pPlaneEnt->setCastShadows(false);
	Ogre::SceneNode* floorNode = mSceneMgr->createSceneNode("floor1");
	mSceneMgr->getRootSceneNode()->addChild(floorNode);
	floorNode->attachObject(pPlaneEnt);

	/*create cube
	Create a cube of 4*4*4 with center at origin
	first create cube entity from ogre model using the mesh
	cube.mesh (which is size 100*100*100)*/
	Ogre::Entity *cube = mSceneMgr->createEntity("cube","cube.mesh");
	cube->setMaterialName("Examples/RustySteel");
	Ogre::SceneNode* cubeNode = mSceneMgr->createSceneNode("cubeNode");
	mSceneMgr->getRootSceneNode()->addChild(cubeNode);
	cubeNode->attachObject(cube);
	cube->setCastShadows(true);
	float cubeModelLength = 100;
	float cubeLength = 4;

	//scale it down
	double cubeScale = cubeLength / cubeModelLength;
	cubeNode->scale(cubeScale,cubeScale,cubeScale);
	//position it on the ground
	cubeNode->setPosition(Ogre::Vector3(0,cubeLength/2,0));

	//Create a cylinder of radius = 0.3 and length = 8 with centre at position = (100, 0, 0)		
	Ogre::Entity *cyl = 
		mSceneMgr->createEntity("cylinder", "Barrel.mesh");
	cyl->setMaterialName("Examples/Hilite/Yellow");  
	Ogre::SceneNode *cylNode = 
		mSceneMgr->getRootSceneNode()-> createChildSceneNode( "CylinderNode",Ogre::Vector3::Vector3(100,0,0) );
	cylNode->attachObject( cyl );
	cyl->setCastShadows(true);
	double cylModelRadius = 2.7; // the exact radius of the mesh for // the cylinder model
	double cylModelHeight = 6.2; // the exact length of the mesh for // cylinder model

	// Change size of graphics cylinder to your own size
	double cylRadius = 0.3;  // The new radius for graphics cylinder
	double cylLength = 8;  // The new length for the cylinder
	cylNode->scale(cylRadius/cylModelRadius, cylLength/cylModelHeight, cylRadius/cylModelRadius);
	// Reset the position of cylinder to rest on top of cube
	cylNode->setPosition(0,cylLength/2 + cubeLength,0);

	myCannon = new Cannon(cylNode,Ogre::Vector3(0,cubeLength+cylLength/2,0),cubeLength,(float)cylRadius,(float)cylLength,(float) mSceneMgr->getSceneNode("CylinderNode")->getPosition().y);
	target = new Target(mSceneMgr);
	missile = new Missile(mSceneMgr,cubeLength,cylLength,myCannon);
}

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
	int main(int argc, char *argv[])
#endif
	{
		// Create application object
		TutorialApplication app;

		try {
			app.go();
		} catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
			MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
			std::cerr << "An exception has occured: " <<
				e.getFullDescription().c_str() << std::endl;
#endif
		}

		return 0;
	}

#ifdef __cplusplus
}
#endif
