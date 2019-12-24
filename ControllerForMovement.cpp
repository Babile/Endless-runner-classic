#include "ControllerForMovement.h"
#include "Hole.h"
#include "Box.h"
#include "Extension.h"
#include <Windows.h>
#include <chrono>

bool mainCharactherFalling = false;
bool mainCaracterJumped = false;
bool mainCharacterInHole = false;

int mainCharacterJumpCounter = 0;

float fElapsedTime = 0.0f;

auto tp1 = std::chrono::system_clock::now();
auto tp2 = std::chrono::system_clock::now();

ControllerForMovement::ControllerForMovement(){}

void ControllerForMovement::moveObjects(CollisionDetection* boxColider) {
	tp2 = std::chrono::system_clock::now();
	std::chrono::duration<float> elapsedTime = tp2 - tp1;
	tp1 = tp2;
	fElapsedTime = elapsedTime.count();

	for (int i = 0; i < vectorOfObjects.size(); i++) {
		if (vectorOfObjects[i]->getTypeObject() == 'M') {
			if ((GetAsyncKeyState((unsigned short)'A') & 0x8000) && !mainCharacterInHole) {
				if (vectorOfObjects[i]->getColumn() <= 0 || boxColider->getLeft()) {
					vectorOfObjects[i]->setColumn(vectorOfObjects[i]->getColumn());
					vectorOfObjects[i]->setColumnEnd(vectorOfObjects[i]->getColumnEnd());
				} else {
					vectorOfObjects[i]->setColumn(vectorOfObjects[i]->getColumn() - (gameSpeed * fElapsedTime));
					vectorOfObjects[i]->setColumnEnd(vectorOfObjects[i]->getColumnEnd() - (gameSpeed * fElapsedTime));
				}
			}
			else if ((GetAsyncKeyState((unsigned short)'D') & 0x8000) && !mainCharacterInHole) {
				if ((int)vectorOfObjects[i]->getColumnEnd() >= screenWidth/2 || boxColider->getRight()) {
					vectorOfObjects[i]->setColumn(vectorOfObjects[i]->getColumn());
					vectorOfObjects[i]->setColumnEnd(vectorOfObjects[i]->getColumnEnd());
				} else {
					vectorOfObjects[i]->setColumn(vectorOfObjects[i]->getColumn() + (gameSpeed * fElapsedTime));
					vectorOfObjects[i]->setColumnEnd(vectorOfObjects[i]->getColumnEnd() + (gameSpeed * fElapsedTime));
				}
				stepsCounter++;
			}

			if ((GetAsyncKeyState((unsigned short)32) & 0x8000) && !mainCaracterJumped || GetAsyncKeyState((unsigned short)32)
				&& boxColider->getTop()) {
				mainCaracterJumped = true;
				mainCharacterJumpCounter = 0;
				mainCharactherFalling = false;
			}

			if (mainCaracterJumped && !mainCharactherFalling) {
				if (mainCharacterJumpCounter >= 150 || boxColider->getBotom()) {
					mainCharactherFalling = true;
					break;
				}

				vectorOfObjects[i]->setRow(vectorOfObjects[i]->getRow() - (gameSpeed * fElapsedTime));
				vectorOfObjects[i]->setRowEnd(vectorOfObjects[i]->getRowEnd() - (gameSpeed * fElapsedTime));
				mainCharacterJumpCounter++;
			}
			
			if (mainCharactherFalling && !boxColider->getTop()) {
				if ((int)vectorOfObjects[i]->getRowEnd() >= screenHeight - 3 && !mainCharacterInHole) {
					mainCharactherFalling = false;
					mainCaracterJumped = false;
					mainCharacterJumpCounter = 0;
					break;
				}
				vectorOfObjects[i]->setRow(vectorOfObjects[i]->getRow() + (gameSpeed * fElapsedTime));
				vectorOfObjects[i]->setRowEnd(vectorOfObjects[i]->getRowEnd() + (gameSpeed * fElapsedTime));
			}
		}

		if (vectorOfObjects[i]->getTypeObject() != 'M') {
			if ((GetAsyncKeyState((unsigned short)'D') & 0x8000) && !mainCharacterInHole && !boxColider->getRight()) {
				vectorOfObjects[i]->setColumn(vectorOfObjects[i]->getColumn() - (gameSpeed * fElapsedTime));
				vectorOfObjects[i]->setColumnEnd(vectorOfObjects[i]->getColumnEnd() - (gameSpeed * fElapsedTime));
			}
			if ((int)vectorOfObjects[0]->getColumn() > (int)vectorOfObjects[i]->getColumn() 
				&& (int)vectorOfObjects[0]->getColumnEnd() < (int)vectorOfObjects[i]->getColumnEnd()
				&& (int)vectorOfObjects[0]->getRowEnd() >= screenHeight - 3 && vectorOfObjects[i]->getTypeObject() == 'H') {

				mainCharacterInHole = true;
				mainCharactherFalling = true;
			}
		}
	}
}

void ControllerForMovement::changeObjectsPosition() {
	short int correctPositionOfObject = screenHeight - screenHeightsBeforeUpdate;

	for (int i = 0; i < vectorOfObjects.size(); i++) {
		vectorOfObjects[i]->setRow((float)((int)vectorOfObjects[i]->getRow() + correctPositionOfObject));
		vectorOfObjects[i]->setRowEnd((float)((int)vectorOfObjects[i]->getRowEnd() + correctPositionOfObject));
	}
}

void ControllerForMovement::endGame() {
	if ((int)vectorOfObjects[0]->getRow() > screenHeight) {
		gameState = END;
	}
}