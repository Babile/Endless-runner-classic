#include "BaseObject.h"


float BaseObject::getRow() {
	return this->row;
}

void BaseObject::setRow(float newRow) {
	this->row = newRow;
}

float BaseObject::getColumn() {
	return this->column;
}

void BaseObject::setColumn(float newColumn) {
	this->column = newColumn;
}

float BaseObject::getRowEnd() {
	return this->rowEnd;
}

void BaseObject::setRowEnd(float newRowEnd) {
	this->rowEnd = newRowEnd;
}

float BaseObject::getColumnEnd() {
	return this->columnEnd;
}

void BaseObject::setColumnEnd(float newColumnEnd) {
	this->columnEnd = newColumnEnd;
}

bool BaseObject::getRespondStatus() {
	return this->onTriggerEnter;
}

void BaseObject::setRespondStatus(bool newStatus) {
	this->onTriggerEnter = newStatus;
}
