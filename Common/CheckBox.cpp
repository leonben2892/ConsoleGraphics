#include "CheckBox.h"

CheckBox::CheckBox(short x, short y, string str) 
	: Control(1, x, y, { 2,2 }) , cbValue(str) {}

void CheckBox::setIsChecked(bool check) {
	this->IsChecked = check;
}

bool CheckBox::getIsChecked() {
	return this->IsChecked;
}

void CheckBox::setCbValue(string s) {
	this->cbValue = s;
}

string CheckBox::getCbValue() {
	return this->cbValue;
}

void CheckBox::draw(Graphics & g, int x, int y, size_t z) 
{
	bs->drawBorderType(x, y, cord);
	g.write(x + cord.X + 1, y + 1, cbValue);

	if (IsChecked)
		g.write(x + 1, y + 1, "X");
}

bool CheckBox::canGetFocus() { return true; }

void CheckBox::mousePressed(int x, int y, bool isLeft)
{
	// checking if mouse pressed within Checkbox area
	if (y >= this->top && y <= this->top + this->cord.Y)
	{
		if (x >= this->left && x <= this->left + this->cord.X + 1)
		{
			if (this->IsChecked)
				this->IsChecked = false;			
			else
				this->IsChecked = true;
		}
	}
}
