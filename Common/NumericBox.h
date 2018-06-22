#include <string>
#include <Windows.h>
#include "Control.h"

using namespace std;

class NumericBox : public Control
{
private:
	string text;
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	int minValue;
	int maxValue;
	int currValue;

public:
	NumericBox(int bord, short x, short y, COORD cord, int currVal);
	void setMinValue(int minNum) { this->minValue = minNum; };
	int getMinValue() { return minValue; };
	void setMaxValue(int maxNum) { this->maxValue = maxNum; };
	int getMaxValue() { return this->maxValue; };
	void draw(Graphics & g, int x, int y, size_t z);
	bool canGetFocus();
	bool myPureFunction() { return true; };

	void mousePressed(int x, int y, bool isLeft, Graphics &g);

};
