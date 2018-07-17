#include "NumericBox.h"

NumericBox::NumericBox(int bord, short x, short y, COORD cor, int currVal)
	: Control(bord,x,y,cor), currValue(currVal) , minValue(0), maxValue(50)
{
	if (cor.Y < 4) 
		cord.Y = 4;
}

bool NumericBox::setCurrentValue(int currValue) {
	if (currValue < minValue || currValue > maxValue)
		return false;
	else {
		this->currValue = currValue;
		return true;
	}
}

void NumericBox::draw(Graphics& g, int x, int y, size_t z) {
	COORD c;
	c.X = x;
	c.Y = y;

	g.setBackground(this->background);
	g.setForeground(this->foreground);

	bs->drawBorderType(x, y, cord);
	// drawing "-"
	bs->drawBorderType(x + 1, y + 1, { 2,2 });
	g.write(c.X + 2, c.Y + 2, "\x2D");
	/**********************/

	// drawing the value
	g.write(c.X + 7, c.Y + 2, std::to_string(currValue));
	
	/**********************/

	// drawing "+"
	bs->drawBorderType((short)(x + cord.X - 3), y + 1, { 2,2 });
	g.write(c.X + cord.X - 2, c.Y + 2, "\x2B");
	/**********************/
}


bool NumericBox::canGetFocus() 
{ 
	return false; 
}

void NumericBox::mousePressed(int x, int y, bool isLeft, Graphics &g)
{	
	if (x >= this->left &&  x <= this->left +3 && y >= this->top + 1 && y <= this->top +3)		// if "minus" button pressed
	{
		if (currValue > minValue)
		{
			currValue -= 1;
		}
	}

	else if (x <= this->left + this->cord.X - 1 && x >= this->left + this->cord.X - 4 && y >= this->top + 1 && y <= this->top + 3)
	{
		if (currValue < maxValue)
		{
			currValue += 1;
		}
	}
}