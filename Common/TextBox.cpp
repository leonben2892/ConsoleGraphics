#include "TextBox.h"

TextBox::TextBox(int bord,short x, short y, COORD cor) 
	:Control(bord,x,y,cor)  {}

void TextBox::draw(Graphics & g, int x, int y, size_t z)
{
	bs->drawBorderType(x, y, cord);
	SetConsoleCursorPosition(out, { left + 1,top + 1 });
}

bool TextBox::canGetFocus() { return true; }

void TextBox::mousePressed(int x, int y, bool isLeft)
{
	// checking if mouse pressed within textbox area
	if (y > this->top + 1 && y < this->top + this->cord.Y)
	{
		if (x > this->left + 1 && x < this->left + this->cord.X - 1)
		{
			SetConsoleCursorPosition(out, { (SHORT)x ,(SHORT) y });
		}
	}
}

void TextBox::keyDown(int keycode, char character)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	if (keycode == 8)
	{
		if (info.dwCursorPosition.X - 1 == this->left)    // if we trying to delete char but we in text border position
			return;
		cout << '\x08';
		cout << '\x0';
	}

	else if (info.dwCursorPosition.X == this->left + this->cord.X)    // if we trying to exceed the textbox border
		return;

	else if (keycode == '\x0D')      // if ENTER key pressed
		// need to go down line

	cout << character;      // printing the selected key
}