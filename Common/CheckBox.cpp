#include "CheckBox.h"

CheckBox::CheckBox(short x, short y, string str) {
	this->left = x;
	this->top = y;
	this->cbValue = str;
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

void CheckBox::draw(Graphics & g, int x, int y, COORD coord) {
	COORD c;
	c.X = this->left;
	c.Y = this->top;

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	SetConsoleCursorPosition(out, { c.X, c.Y });
	cout << '\xDA';	//top left corner
	cout << '\xBF'; //horizontal line
	cout << '\xBF';	//top right corner
	SetConsoleCursorPosition(out, { c.X, c.Y+1 });
	cout << '\xB3'; //vertical line
	SetConsoleCursorPosition(out, { c.X+2, c.Y + 1 });
	cout << '\xB3';	//vertical line
	cout << " " + this->cbValue;	//checkbox string value
	SetConsoleCursorPosition(out, { c.X, c.Y + 2 });
	cout << '\xC0';	//bottom left corner
	cout << '\xBF';	//horizontal line
	cout << '\xD9';	//bottom right corner

}
