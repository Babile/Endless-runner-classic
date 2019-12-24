#include "Box.h"

Box::Box(float row, float rowEnd, float column, float columnEnd) {
	this->row = row;
	this->rowEnd = rowEnd;
	this->column = column;
	this->columnEnd = columnEnd;
	this->typeObject = 'B';
}

char Box::getPrintSymbols() {
	return '#';
}

char Box::getTypeObject() {
	return this->typeObject;
}
