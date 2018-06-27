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

void CheckBox::mousePressed(int x, int y, bool isLeft, Graphics &g)
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

void CheckBox::keyDown(int keyCode, char charecter, Graphics &g)
{
	COORD c = g.getCursorPos();
		if (keyCode == 32 || keyCode == 13)   //Space or Enter key
		{
			if (IsChecked)
				IsChecked = false;
			else
				IsChecked = true;
		}

}

void CheckBox::setBackGround(Color FGcolor, Color BGcolor )
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD attributes = 0;
	switch (FGcolor)
	{
	case Color::Black:	break;
	case Color::Blue:	attributes |= FOREGROUND_BLUE; break;
	case Color::Green:	attributes |= FOREGROUND_GREEN; break;
	case Color::Red:	attributes |= FOREGROUND_RED; break;
	case Color::Cyan:	attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN; break;
	case Color::Purple:	attributes |= FOREGROUND_BLUE | FOREGROUND_RED; break;
	case Color::Orange: attributes |= FOREGROUND_GREEN | FOREGROUND_RED; break;
	case Color::White:	attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED; break;
	}

	switch (BGcolor)
	{
	case Color::Black:	break;
	case Color::Blue:	attributes |= BACKGROUND_BLUE; break;
	case Color::Green:	attributes |= BACKGROUND_GREEN; break;
	case Color::Red:	attributes |= BACKGROUND_RED; break;
	case Color::Cyan:	attributes |= BACKGROUND_BLUE | BACKGROUND_GREEN; break;
	case Color::Purple:	attributes |= BACKGROUND_BLUE | BACKGROUND_RED; break;
	case Color::Orange: attributes |= BACKGROUND_GREEN | BACKGROUND_RED; break;
	case Color::White:	attributes |= BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED; break;
	}
	SetConsoleTextAttribute(out, attributes);
	//graphic.setBackground(color);
}
