#include "MainCharacter.h"

MainCharacter::MainCharacter(float row, float rowEnd, float column, float columnEnd) {
	this->row = row;
	this->rowEnd = rowEnd;
	this->column = column;
	this->columnEnd = columnEnd;
	this->typeObject = 'M';
}

char MainCharacter::getPrintSymbols() {
	return '@';
}

char MainCharacter::getTypeObject() {
	return this->typeObject;
}
