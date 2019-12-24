#ifndef MARIO_H
#define MARIO_H

#include "BaseObject.h"

class MainCharacter : public BaseObject {
public:
	MainCharacter(float r, float rE, float c, float cE);

	// Inherited via BaseObject
	virtual char getPrintSymbols() override;
	virtual char getTypeObject() override;
};

#endif