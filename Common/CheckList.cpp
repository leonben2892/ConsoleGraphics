#include "CheckList.h"

CheckList::CheckList(int bord, short x, short y, COORD cor, string str[]) {
	//Control::borderType = bord;
	Control::left = x;
	Control::top = y;
	Control::cord = cor;
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
	for (short i = 0; i < (short)str->size(); i++) {
		allCheckBoxes.push_back(new CheckBox(x + 2,y + (i *3),str[i]));
	}
}

void CheckList::draw(Graphics & g, int x, int y, size_t z)
{
	//switch (borderType)
	//{
	//	case 0:
	//		break;
	//	case 1:
	//		border.drawSingleBorder(x, y, cord);
	//		break;

	//	case 2:
	//		border.drawDoubleBorder(x, y, cord);
	//		break;

	//	default:
	//		break;
	//	}
	bs->drawBorderType(x, y, cord);
	for (size_t i = 0; i < allCheckBoxes.size(); ++i)
		allCheckBoxes[i]->draw(g, (short)(x + 3) ,(short)(y + 1 + (i * 3)) ,z);
}

bool CheckList::canGetFocus() { return true; }