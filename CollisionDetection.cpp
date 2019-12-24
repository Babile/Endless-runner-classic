#include "CollisionDetection.h"
#include "Extension.h"

BaseObject* collisionObject = nullptr;

CollisionDetection::CollisionDetection() {}

BaseObject* CollisionDetection::getCollisionObject() {
	for (int i = 1; i < vectorOfObjects.size(); i++) {
		if (vectorOfObjects[i]->getTypeObject() != 'H') {
			if (((int)vectorOfObjects[0]->getRow() <= (int)vectorOfObjects[i]->getRowEnd() &&
				(int)vectorOfObjects[0]->getRowEnd() >= (int)vectorOfObjects[i]->getRow()) &&
				((int)vectorOfObjects[0]->getColumnEnd() >= (int)vectorOfObjects[i]->getColumn() &&
				(int)vectorOfObjects[0]->getColumn() <= (int)vectorOfObjects[i]->getColumnEnd())) {

				return vectorOfObjects[i];
			}
		}
	}
	return nullptr;
}

CollisionDetection* CollisionDetection::onBoxCollision() {
	top = false;
	right = false;
	left = false;
	bottom = false;
	
	collisionObject = getCollisionObject();

	if (collisionObject == nullptr){
		return this;
	}
	
	if ((int)collisionObject->getRow() >= (int)vectorOfObjects[0]->getRow() ||
		(int)collisionObject->getRowEnd() <= (int)vectorOfObjects[0]->getRowEnd()) {
		if ((int)collisionObject->getColumn() >= (int)vectorOfObjects[0]->getColumnEnd()) {
			right = true;
		}
		else if ((int)collisionObject->getColumnEnd() <= (int)vectorOfObjects[0]->getColumn()) {
			left = true;
		}
	}
	if ((int)collisionObject->getColumn() <= (int)vectorOfObjects[0]->getColumn() ||
		(int)collisionObject->getColumnEnd() >= (int)vectorOfObjects[0]->getColumnEnd()) {
		if ((int)collisionObject->getRow() == (int)vectorOfObjects[0]->getRowEnd()) {
			top = true;
		}
		else if ((int)collisionObject->getRowEnd() == (int)vectorOfObjects[0]->getRow()) {
 			bottom = true;
		}
	}
	
	return this;
}

bool CollisionDetection::getTop() {
	return this->top;
}

bool CollisionDetection::getBotom() {
	return this->bottom;
}

bool CollisionDetection::getRight() {
	return this->right;
}

bool CollisionDetection::getLeft() {
	return this->left;
}
