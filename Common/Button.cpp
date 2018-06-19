#include "Button.h"

Button::Button(int bord, short x, short y, COORD cor, string str) {
	this->borderType = bord;
	this->left = x;
	this->top = y;
	this->cord = cor;
	this->btnValue = str;
}

void Button::setBtnValue(string str) {
	this->btnValue = str;
}

string Button::getBtnValue() {
	return this->btnValue;
}

void Button::draw(Graphics & g, int x, int y, size_t z) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	switch (borderType)
	{
	case 0:
		break;
	case 1:
		border.drawSingleBorder(x, y, cord);	// drawing the numeric box
		break;
	case 2:
		border.drawDoubleBorder(x, y, cord);	// drawing the numeric box
		break;
	default:
		break;
	}
	SetConsoleCursorPosition(out, { (SHORT)(x + 1), (SHORT)(y + 1) });
	cout << this->btnValue;
}

bool Button::canGetFocus() { return false; }

void Button::mousePressed(int x, int y, bool isLeft)
{
	if (x > left  && x < left + cord.X && y > top && y < top + cord.Y)
	{
		// do something!!!
	}
}