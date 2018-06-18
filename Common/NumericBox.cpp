#include "NumericBox.h"

NumericBox::NumericBox(int bord, short x, short y, COORD cor, int currVal) {
	this->borderType = bord;
	this->left = x;
	this->top = y;
	this->cord = cor;
	this->currValue = currVal;
	this->minValue = 0;
	this->maxValue = 50;
}

void NumericBox::draw(Graphics & g, int x, int y, size_t z) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	COORD c;
	c.X = x;
	c.Y = y;

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
	// drawing "-"
	border.drawSingleBorder(x + 1, y + 1, { 2,2 });
	SetConsoleCursorPosition(out, { (SHORT)(c.X + 2), (SHORT)(c.Y + 2) });
	cout << '\x2D';	
	/**********************/

	// drawing the value
	SetConsoleCursorPosition(out, { (SHORT)(c.X + 7), (SHORT)(c.Y + 2) });
	cout << this->currValue; 
	/**********************/

	// drawing "+"
	border.drawSingleBorder((SHORT)(x + cord.X - 3), y + 1, { 2,2 });
	SetConsoleCursorPosition(out, { (SHORT)(c.X + cord.X -2), (SHORT)c.Y + 2 });
	cout << '\x2B'; 
	/**********************/
}


bool NumericBox::canGetFocus() 
{ 
	return false; 
}

void NumericBox::mousePressed(int x, int y, bool isLeft)
{
	if (!isLeft)
		return;
	if (x == left + 2 && y == top + 1)		// if "minus" button pressed
	{
		if (currValue > minValue)
		{
			currValue -= 1;
			/// need to print the current value again
		}

		else if (x == cord.X - 2 && y == top + 1)
		{
			if (currValue < maxValue)
			{
				currValue += 1;
				/// need to print the current value again
			}
		}
			
	}
}