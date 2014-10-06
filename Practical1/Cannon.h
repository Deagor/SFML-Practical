#ifndef __Cannon_h_
#define __Cannon_h_

class Cannon
{
protected:
	Ogre::Vector3 m_position;
	Ogre::Quaternion m_orientation;
	float m_lengthBarrel;
	float m_baseCubeLength;
	float m_radiusBarrel;
	float m_heightAboveGround;
	Ogre::Vector3 m_direction;
	Ogre::SceneNode * m_gunBarrel;
	
	public:
	Cannon(Ogre::SceneNode *, Ogre::Vector3,float, float, float,float);
				
	void rotate(OIS::Keyboard*);
	void rotate();
	//void translate();
	void setOrientation(Ogre::Quaternion);
	Ogre::Quaternion getOrientation();
	Ogre::Vector3 getPosition();
	float getLengthBarrel();
	float getRadiusBarrel();
	float getBaseCubeLength();
	float getHeightAboveGround();
	Ogre::SceneNode* getGunBarrel() { return m_gunBarrel; }
		
	~Cannon();

};

#endif
