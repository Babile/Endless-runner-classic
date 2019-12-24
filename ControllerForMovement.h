#ifndef CONTROLLERFORMOVEMENT_H
#define CONTROLLERFORMOVEMENT_H
#include "CollisionDetection.h"

class ControllerForMovement {
public:
	ControllerForMovement();
	void moveObjects(CollisionDetection*);
	void checkObjectStatus();
	void changeObjectsPosition();
	void endGame();
};

#endif
