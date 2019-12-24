#include "ControllerResponse.h"
#include "Extension.h"
#include "Hole.h"
#include "Box.h"
#include "MainCharacter.h"
#include <ctime>

int randomNumber(int, int);
bool respondObject = false;

MainCharacter *mainCharacterP;

ControllerResponse::ControllerResponse() {
	mainCharacterP = new MainCharacter(22.0f, 27.0f, 0.0f, 7.0f);
	vectorOfObjects.push_back(mainCharacterP);
	srand((unsigned)time(0));
}

void ControllerResponse::checkObjectStatusAndRespond() {
	for (int i = 0; i < vectorOfObjects.size(); i++) {
		if (vectorOfObjects[i]->getTypeObject() != 'M') {
			if ((int)vectorOfObjects[i]->getColumnEnd() <= -20) {
				delete vectorOfObjects[i];
				vectorOfObjects.erase(vectorOfObjects.begin() + i);
			}
			if (stepsCounter >= 17 && (int)vectorOfObjects[i]->getColumnEnd() < screenWidth
				&& !vectorOfObjects[i]->getRespondStatus()) {

				stepsCounter = 0;
				respondObject = false;
				vectorOfObjects[i]->setRespondStatus(true);
			}
		}
		else if (!respondObject) {
			int boxPlaceRespond;
			switch (randomNumber(0, 3)) {
			case 0:
				vectorOfObjects.push_back(new Hole((float)screenHeight - 3.0f, (float)screenHeight,
					(float)screenWidth + 30.0f, (float)screenWidth + 47.0f));
				break;
			case 1:
				boxPlaceRespond = randomNumber(12, 23);
				vectorOfObjects.push_back(new Box((float)boxPlaceRespond, (float)boxPlaceRespond + 3.0f,
					(float)screenWidth + 30.0f, (float)screenWidth + 56.0f));
				break;
			case 2:
				vectorOfObjects.push_back(new Box((float)screenHeight - 9.0f, (float)screenHeight - 3.0f,
					(float)screenWidth + 30.0f, (float)screenWidth + 40.0f));
				break;
			default:
				break;
			}
			respondObject = true;
		}
	}
}

int randomNumber(int minNumber, int maxNumber) {
	return (rand() % (maxNumber - minNumber)) + minNumber;
}