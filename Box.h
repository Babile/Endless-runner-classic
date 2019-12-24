#ifndef BOX_H
#define BOX_H
#include "BaseObject.h"

class Box: public BaseObject {	
public:
	Box(float r, float rE, float c, float cE);

	// Inherited via BaseObject
	virtual char getPrintSymbols() override;
	virtual char getTypeObject() override;
};

#endif

