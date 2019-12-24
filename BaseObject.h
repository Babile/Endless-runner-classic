#ifndef BASEOBJECT_H
#define BASEOBJECT_H

class BaseObject {
protected:
	float row, rowEnd, column, columnEnd;
	char typeObject;
	bool onTriggerEnter = false;
public:
	float getRow();
	void setRow(float);
	float getColumn();
	void setColumn(float);
	float getRowEnd();
	void setRowEnd(float);
	float getColumnEnd();
	void setColumnEnd(float);
	bool getRespondStatus();
	void setRespondStatus(bool);
	virtual char getPrintSymbols() = 0;
	virtual char getTypeObject() = 0;

};

#endif
