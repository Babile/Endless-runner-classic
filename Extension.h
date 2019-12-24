#ifndef EXTENSION_H 
#define EXTENSION_H
#include "BaseObject.h"
#include <vector>

#define vectorOfObjects GameScene::vectorOfObjectss
#define screenHeight GameScene::screenHeights
#define screenWidth GameScene::screenWidths
#define screenHeightsBeforeUpdate GameScene::screenHeightsBeforeUpdates
#define stepsCounter GameScene::stepsCunterMainCharater
#define gameState GameScene::states
#define gameSpeed GameScene::gameSpeeds

enum GameState {
	RUNNING,
	PAUSED,
	MENU,
	END
};

static class GameScene {
public:
	static GameState states;
	static std::vector<BaseObject*> vectorOfObjectss;
	static int screenHeights;
	static int screenWidths;
	static int screenHeightsBeforeUpdates;
	static int stepsCunterMainCharater;
	static int gameSpeeds;
};

#endif