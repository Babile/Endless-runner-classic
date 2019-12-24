#include "Hole.h"


Hole::Hole(float row, float rowEnd, float column, float columnEnd) {
	this->row = row;
	this->rowEnd = rowEnd;
	this->column = column;
	this->columnEnd = columnEnd;
	this->typeObject = 'H';
}

char Hole::getPrintSymbols() {
	return ' ';
}

char Hole::getTypeObject() {
	return this->typeObject;
}
