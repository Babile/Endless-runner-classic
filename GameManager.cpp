#include "GameManager.h"
#include "View.h"
#include "ControllerForMovement.h"
#include "ControllerResponse.h"
#include "CollisionDetection.h"
#include "Extension.h"
#include <Windows.h>

void cleanStuff();
void gameRunning();
void gamePaused();
void checkKeyState();

View *viewP;
ControllerForMovement* controllerForMovementP;
CollisionDetection* collisionDetectorP;
ControllerResponse* controllerResponseP;

GameManager::GameManager() {
	viewP = new View();
	controllerForMovementP = new ControllerForMovement();
	collisionDetectorP = new CollisionDetection();
	controllerResponseP = new ControllerResponse();
	gameState = RUNNING;
}

void GameManager::gameDemo() {
	bool endGamed = false;

	while (!endGamed){
		checkKeyState();
		switch (gameState) {
			case RUNNING:
				gameRunning();
				break;
			case PAUSED: 
				gamePaused();
				break;
			case MENU:
				
				break;
			case END:
				endGamed = true;
				break;
			default:
				throw ("Not implemented state");
				break;
		}
	}

	cleanStuff();
}

void gameRunning() {
	controllerForMovementP->moveObjects(collisionDetectorP->onBoxCollision());
	controllerResponseP->checkObjectStatusAndRespond();
	if (viewP->updateScreenSize()) {
		controllerForMovementP->changeObjectsPosition();
	}
	viewP->print();
	controllerForMovementP->endGame();
}

void gamePaused() {
	if (viewP->updateScreenSize()) {
		controllerForMovementP->changeObjectsPosition();
	}
	viewP->printPaused();	
}

void checkKeyState() {
	if (GetKeyState(VK_ESCAPE) & 0x8000) {
		Sleep(200);
		if (gameState == RUNNING) {
			gameState = PAUSED;
		} 
		else if (gameState == PAUSED) {
			gameState = RUNNING;
		}
	}
}

void cleanStuff() {
	for (auto &element : vectorOfObjects) {
		delete element;
	}
	vectorOfObjects.clear();
	viewP->clearStuffView();

	delete viewP;
	delete controllerForMovementP;
	delete collisionDetectorP;
	delete controllerResponseP;
}