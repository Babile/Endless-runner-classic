#include "Extension.h"

std::vector<BaseObject*> GameScene::vectorOfObjects;
int GameScene::screenWidths = 120;
int GameScene::screenHeights = 30;
int GameScene::screenHeightsBeforeUpdates = screenHeights;
int GameScene::stepsCunterMainCharater = 0;
int GameScene::gameSpeeds = 20.0f;
GameState GameScene::states = RUNNING;