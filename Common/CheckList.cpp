#include "CheckList.h"

CheckList::CheckList(int bord, short x, short y, COORD cor, string str[], short arrSize) {
	Control::borderType = bord;
	Control::left = x;
	Control::top = y;
	Control::cord = cor;
	for (short i = 0; i < arrSize; i++) {
		this->checkBoxesValues[i] = str[i];
	}
}

void CheckList::draw(Graphics & g, int x, int y, size_t z) {
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
}

bool CheckList::canGetFocus() { return true; }