#include "CheckList.h"

CheckList::CheckList(int bord, short x, short y, COORD cor, string str[]) 
	:Control::Control(bord,x,y,cor)
{
	for (short i = 0; i < (short)str->size(); i++) {
		allCheckBoxes.push_back(new CheckBox(x + 2,y + (i *3),str[i]));
	}
}

void CheckList::draw(Graphics & g, int x, int y, size_t z)
{
	bs->drawBorderType(x, y, cord);
	for (size_t i = 0; i < allCheckBoxes.size(); ++i)
		allCheckBoxes[i]->draw(g, (short)(x + 3) ,(short)(y + 1 + (i * 3)) ,z);
}

bool CheckList::canGetFocus() { return true; }

void CheckList::mousePressed(int x, int y, bool isLeft, Graphics &g)
{
	for (auto child : allCheckBoxes)
	{
		child->mousePressed(x, y, isLeft, g);
	}
}

void CheckList::keyDown(int keyCode, char charecter, Graphics &g)
{
	for (auto child : allCheckBoxes)
	{
		child->keyDown(keyCode, charecter, g);
	}
}