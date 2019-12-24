#include "View.h"
#include "Box.h"
#include "Hole.h"
#include "Extension.h"
#include <Windows.h>

bool printObject;
std::string s[3] = { "Resume", "Option", "Menu" };
std::string corectOption;

//COLORREF redColor = RGB(255, 0, 0);
//COLORREF blueColor = RGB(0, 0, 255);
//COLORREF greenColor = RGB(0, 255, 0);

char *screen = new char[screenWidth * screenHeight];
char *screenOnPause = new char[screenWidth * screenHeight];
HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
DWORD dwBytesWritten = 0;

View::View() {
	SetConsoleActiveScreenBuffer(hConsole);
}

void View::print() {
	for (int i = 0; i < screenHeight; i++) {
		for (int j = 0; j < screenWidth; j++) {
			printObject = false;
			for (int k = 0; k < vectorOfObjects.size(); k++) {
				//treba doraditi ovaj uslov. Treba izracunati koliko tacno treba da se pomeri sve da bi ispisalo kako treba
				if (((float)i - 0.4f > vectorOfObjects[k]->getRow() && (float)i - 0.4f < vectorOfObjects[k]->getRowEnd()) &&
					((float)j + 0.3f > vectorOfObjects[k]->getColumn() && (float)j + 0.3f < vectorOfObjects[k]->getColumnEnd())) {
					screen[i * screenWidth + j] = vectorOfObjects[k]->getPrintSymbols();
					printObject = true;
					break;
				}
			}
			if (i > screenHeight - 3 && i < screenHeight && !printObject) {
				screen[i * screenWidth + j] = '$';
			} 
			else if (!printObject) {
				screen[i * screenWidth + j] = ' ';
			}
		}
	}

	WriteConsoleOutputCharacter(hConsole, screen, screenWidth * screenHeight, { 0,0 }, &dwBytesWritten);
}

void View::printPaused() {
	for (int i = 0; i < screenHeight; i++) {
		for (int j = 0; j < screenWidth; j++) {
			if ((i > screenHeight / 2 - 5 && i < screenHeight / 2 + 5) && (j > screenWidth/2 - 10 && j < screenWidth/2 + 10)) {
				screenOnPause[i * screenWidth + j] = ' ';
			} else {
				screenOnPause[i * screenWidth + j] = static_cast<unsigned char>(177);
			}
		}
	}

	WriteConsoleOutputCharacter(hConsole, screenOnPause, screenWidth * screenHeight, { 0,0 }, &dwBytesWritten);
}


bool View::updateScreenSize() {
	short int columns, rows;

	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
	columns = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;
	rows = bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1;
	
	if (screenWidth != columns || screenHeight != rows) {
		screenHeightsBeforeUpdate = screenHeight;
		screenWidth = columns;
		screenHeight = rows;
		bufferInfo.dwSize.X = columns;
		bufferInfo.dwSize.Y = rows;
		SetConsoleScreenBufferSize(hConsole, bufferInfo.dwSize);
		delete[] screen;
		delete[] screenOnPause;
		screen = new char[screenWidth * screenHeight];
		screenOnPause = new char[screenWidth * screenHeight];
		return true;
	} 
	return false;
}

void View::clearStuffView() {
	delete[] screen;
	delete[] screenOnPause;
}

