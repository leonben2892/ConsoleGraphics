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
