#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include "BaseObject.h"

class CollisionDetection {
private:
	bool top, bottom, left, right;
public:
	CollisionDetection();
	BaseObject* getCollisionObject();
	CollisionDetection* onBoxCollision();
	bool getTop();
	bool getBotom();
	bool getRight();
	bool getLeft();
};

#endif