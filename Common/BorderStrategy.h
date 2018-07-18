#include <Windows.h>
#include <iostream>

#include "Graphics.h"

using namespace std;

class BorderStrategy {
protected:
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	int x;
	int y;
	COORD c;
	void draw(char topLeft, char hrLine, char topRight, char vrLine, char botoomLeft, char bottomRight, int x, int y, COORD cord, Graphics& g);
	void drawLine(char vrLine);
public:
	virtual void drawBorderType(int, int, COORD , Graphics& g) {};
};

class NoBorder : public BorderStrategy {
	void drawBorderType(int,int,COORD, Graphics& g);
};

class SingleBorder : public BorderStrategy {
	void drawBorderType(int,int,COORD, Graphics& g);
};

class DoubleBorder : public BorderStrategy {
	void drawBorderType(int,int,COORD, Graphics& g);
};