#include "CheckBox.h"

CheckBox::CheckBox(short x, short y, string str) {
	left = x;
	top = y;
	this->cbValue = str;
	cord = { 5,5 };
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
	SetConsoleCursorPosition(out, { cord.X + 1, (SHORT) y + 1 });
	cout << this->cbValue;
}
