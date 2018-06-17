#include "NumericBox.h"

NumericBox::NumericBox(int bord, short x, short y, COORD cor, int currVal) {
	this->borderType = bord;
	this->left = x;
	this->top = y;
	this->cord = cor;
	this->currValue = currVal;
}

void NumericBox::draw(Graphics & g, int x, int y, size_t z) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	COORD c;
	c.X = x;
	c.Y = y;

	//Drawing "-"
	switch (borderType)
	{
	case 0:
		break;
	case 1:
		border.drawSingleBorder(x, y, cord);
		break;
	case 2:
		border.drawDoubleBorder(x, y, cord);
		break;
	default:
		break;
	}
	SetConsoleCursorPosition(out, { (SHORT)(c.X+1), (SHORT)(c.Y+1) });
	cout << '\x2D';

	//Drawing current number
	SetConsoleCursorPosition(out, { (SHORT)(c.X + 3),(SHORT) y});
	this->cord.X += 3;
	switch (borderType)
	{
	case 0:
		break;
	case 1:
		border.drawSingleBorder(c.X+3, y, cord);
		break;
	case 2:
		border.drawDoubleBorder(c.X+3, y, cord);
		break;
	default:
		break;
	}
	SetConsoleCursorPosition(out, { (SHORT)(c.X + 4), (SHORT)(c.Y + 1) });
	cout << this->currValue;

	//Drawing "+"
	SetConsoleCursorPosition(out, { (SHORT)(c.X + 6), (SHORT)y });
	this->cord.X += 3;
	switch (borderType)
	{
	case 0:
		break;
	case 1:
		border.drawSingleBorder(c.X + 6, y, cord);
		break;
	case 2:
		border.drawDoubleBorder(c.X + 6, y, cord);
		break;
	default:
		break;
	}
	SetConsoleCursorPosition(out, { (SHORT)(c.X + 7), (SHORT)(c.Y + 1) });
	cout << '\x2B';
}


bool NumericBox::canGetFocus() { return false; }