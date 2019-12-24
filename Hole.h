#ifndef HOLE_H
#define HOLE_H
#include "BaseObject.h"

class Hole : public BaseObject {
public:
	Hole(float r, float rE, float c, float cE);

	// Inherited via BaseObject
	virtual char getPrintSymbols() override;
	virtual char getTypeObject() override;
};
#endif
