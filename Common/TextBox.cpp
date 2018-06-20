#include "TextBox.h"

TextBox::TextBox(int bord,short x, short y, COORD cor)
{
	Control::left = x;
	Control::top = y;
	Control::cord = cor;
	//Control::borderType = bord;
	switch (bord) {
	case 0:
		bs = new NoBorder();
		break;
	case 1:
		bs = new SingleBorder();
		break;
	case 2:
		bs = new DoubleBorder();
		break;
	default:
		break;
	}
}

void TextBox::draw(Graphics & g, int x, int y, size_t z)
{
	//switch (borderType)
	//{
	//case 0:
	//	break;
	//case 1:
	//	border.drawSingleBorder(x, y, cord);
	//	break;

	//case 2:
	//	border.drawDoubleBorder(x, y, cord);
	//	break;

	//default:
	//	break;
	//}
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

//void TextBox::keyDown(int keycode, char character)
//{
//	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
//	
//	if (keycode == 8)
//	{
//		if (info.dwCursorPosition.X - 1 == this->left)    // if we trying to delete char but we in text border position
//			return;
//		cout << '\x08';
//		cout << '\x0';
//	}
//
//	else if (info.dwCursorPosition.X == this->left + this->cord.X)    // if we trying to exceed the textbox border
//		return;
//
//	else if (keycode == '\x0D')      // if ENTER key pressed
//		// need to go down line
//
//	cout << character;      // printing the selected key
//}