#include <Windows.h>
#include <iostream>

using namespace std;

class BorderStrategy {
protected:
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	int x;
	int y;
	COORD c;
	void draw(char topLeft, char hrLine, char topRight, char vrLine, char botoomLeft, char bottomRight, int x, int y, COORD cord);
public:
	virtual void drawBorderType(int, int, COORD) {};
};

class NoBorder : public BorderStrategy {
	void drawBorderType(int,int,COORD);
};

class SingleBorder : public BorderStrategy {
	void drawBorderType(int,int,COORD);
};

class DoubleBorder : public BorderStrategy {
	void drawBorderType(int,int,COORD);
};