#include "CheckBox.h"

CheckBox::CheckBox(short x, short y, string str) {
	Control::left = x;
	Control::top = y;
	this->cbValue = str;
	Control::cord = { 2, 2 };
}

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
	border.drawSingleBorder(x, y, cord);
	SetConsoleCursorPosition(out, { (SHORT)(x + cord.X + 1), (SHORT) y + 1 });
	cout << this->cbValue;
}

bool CheckBox::canGetFocus() { return true; }

void CheckBox::mousePressed(int x, int y, bool isLeft)
{
	// checking if mouse pressed within Checkbox area
	if (y == this->top + 1)
	{
		if (x > this->left + 1 && x < this->left + this->cord.X - 1)
		{
			SetConsoleCursorPosition(out, { (SHORT)x ,(SHORT)y });
			if (this->IsChecked) {
				cout << '\x20';
				this->IsChecked = false;
			}
			
			else {
				cout << "X";
				this->IsChecked = true;
			}
		}
		SetConsoleCursorPosition(out,{ (SHORT)x +1 , (SHORT)y +1 });
	}
}
