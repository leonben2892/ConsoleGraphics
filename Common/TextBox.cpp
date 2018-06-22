#include "TextBox.h"

TextBox::TextBox(int bord,short x, short y, COORD cor) 
	:Control(bord,x,y,cor)  {}

void TextBox::draw(Graphics & g, int x, int y, size_t z)
{
	bs->drawBorderType(x, y, cord);
	g.write(x + this->text.length(), y + 1, this->text);
}

bool TextBox::canGetFocus() { return true; }

void TextBox::mousePressed(int x, int y, bool isLeft, Graphics &g)
{
	// checking if mouse pressed within textbox area
	if (g.isInside(x, y, left, top, left + cord.X, top + cord.Y))
	{
		g.moveTo(x, y);
	}
		
}

void TextBox::keyDown(int keycode, char character, Graphics& g)
{
	COORD c = g.getCursorPos();
	if (g.isInside(c.X, c.Y, this->left, this->top, this->left + cord.X, this->top + cord.Y))
	{
		//if (keycode == 8)  // delete key
		//{
		//	if (info.dwCursorPosition.X - 1 == this->left)    // if we trying to delete char but we in text border position
		//		return;
		//	cout << '\x08';
		//	cout << '\x0';
		//}

		//else if (info.dwCursorPosition.X == this->left + this->cord.X)    // if we trying to exceed the textbox border
		//	return;

		if (keycode == '\x0D')      // if ENTER key pressed
		{
			// need to go down line
		}
		//cout << character;      // printing the selected key
		g.write((int)c.X, (int)c.Y, string(1, character));
		this->text.push_back(character);
	}	
}