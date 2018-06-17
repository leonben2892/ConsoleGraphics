#include "TextBox.h"

TextBox::TextBox(int bord,short x, short y, COORD cor)
{
	Control::left = x;
	Control::top = y;
	Control::cord = cor;
	Control::borderType = bord;
}

void TextBox::draw(Graphics & g, int x, int y, size_t z)
{
	switch (borderType)
	{
	case 0:
		break;
	case 1:
		border.drawSingleBorder(x, y, cord);
		break;

	case 2:
		border.drawDoubleBorder(x, y, cord);
		break;

	default:
		break;
	}

	SetConsoleCursorPosition(out, { left + 1,top + 1 });
}