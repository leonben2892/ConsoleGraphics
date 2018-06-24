#include "RadioBox.h"

RadioBox::RadioBox(int bord, short x, short y, COORD cor, string str[])
	:Control::Control(bord, x, y, cor)
{
	for (short i = 0; i < (short)str->size(); i++) {
		allCheckBoxes.push_back(new CheckBox(x + 2, y + (i * 3), str[i]));
	}
}

void RadioBox::draw(Graphics & g, int x, int y, size_t z)
{
	bs->drawBorderType(x, y, cord);
	for (size_t i = 0; i < allCheckBoxes.size(); ++i)
		allCheckBoxes[i]->draw(g, (short)(x + 3), (short)(y + 1 + (i * 3)), z);
}

bool RadioBox::canGetFocus() { return true; }

bool  RadioBox::getSelectedBox() {
	return 0;
};

bool RadioBox::selectBox() {
	return true;
};





void RadioBox::mousePressed(int x, int y, bool isLeft, Graphics &g)
{
	for (auto child : allCheckBoxes)
	{
		child->setIsChecked(false);
		child->mousePressed(x, y, isLeft, g);
	}
}

void RadioBox::keyDown(int keyCode, char charecter, Graphics &g)
{
	for (auto child : allCheckBoxes)
	{
		child->setIsChecked(false);
		child->keyDown(keyCode, charecter, g);
	}
}

void RadioBox::mouseHover(int x, int y, Graphics &g) {

	// checking if mouse pressed within Checkbox area
	if (y >= this->top && y <= this->top + this->cord.Y)
	{
		if (x >= this->left && x <= this->left + this->cord.X + 1)
		{
			//this->colo
		}
	}




};