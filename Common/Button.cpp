#include "Button.h"

Button::Button(int bord, short x, short y, COORD cor, string str) 
	: Control(bord,x,y,cor) , btnValue(str) {}

void Button::setBtnValue(string str) {
	this->btnValue = str;
}

string Button::getBtnValue() {
	return this->btnValue;
}

void Button::draw(Graphics& g, int x, int y, size_t z) 
{
	g.setBackground(this->background);
	g.setForeground(this->foreground);
	bs->drawBorderType(x, y, cord);
	g.write(x + 1, y + 1, btnValue);
}

bool Button::canGetFocus() { return false; }

void Button::mousePressed(int x, int y, bool isLeft, Graphics &g)
{
	if (x > left  && x < left + cord.X && y > top && y < top + cord.Y)
	{
		// do something!!!
	}
}