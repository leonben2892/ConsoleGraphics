#include "NumericBox.h"

NumericBox::NumericBox(int bord, short x, short y, COORD cor, int currVal) {
	//this->borderType = bord;
	this->left = x;
	this->top = y;
	this->cord = cor;
	this->currValue = currVal;
	this->minValue = 0;
	this->maxValue = 50;
	switch (bord) {
	case 0:
		bs = new NoBorder();
		break;
	case 1:
		bs = new SingleBorder();
		break;
	case 2:
		bs = new DoubleBorder();
		break;
	default:
		break;
	}
}

void NumericBox::draw(Graphics & g, int x, int y, size_t z) {
	COORD c;
	c.X = x;
	c.Y = y;

	//switch (borderType)
	//{
	//case 0:
	//	break;
	//case 1:	
	//	border.drawSingleBorder(x, y, cord);	// drawing the numeric box
	//	break;
	//case 2:
	//	border.drawDoubleBorder(x, y, cord);	// drawing the numeric box
	//	break;
	//default:
	//	break;
	//}
	bs->drawBorderType(x, y, cord);
	// drawing "-"
	//border.drawSingleBorder(x + 1, y + 1, { 2,2 });
	bs->drawBorderType(x + 1, y + 1, { 2,2 });
	SetConsoleCursorPosition(out, { (short)(c.X + 2), (short)(c.Y + 2) });
	cout << '\x2D';	
	/**********************/

	// drawing the value
	SetConsoleCursorPosition(out, { (short)(c.X + 7), (short)(c.Y + 2) });
	cout << this->currValue; 
	/**********************/

	// drawing "+"
	//border.drawSingleBorder((SHORT)(x + cord.X - 3), y + 1, { 2,2 });
	bs->drawBorderType((short)(x + cord.X - 3), y + 1, { 2,2 });
	SetConsoleCursorPosition(out, { (short)(c.X + cord.X -2), (short)c.Y + 2 });
	cout << '\x2B'; 
	/**********************/
}


bool NumericBox::canGetFocus() 
{ 
	return false; 
}

void NumericBox::mousePressed(int x, int y, bool isLeft)
{
	if (x == left + 2 && y == top + 2)		// if "minus" button pressed
	{
		if (currValue > minValue)
		{
			currValue -= 1;
		}
	}

	else if (x == left + cord.X - 2 && y == top + 2)
	{
		if (currValue < maxValue)
		{
			currValue += 1;
		}
	}
}