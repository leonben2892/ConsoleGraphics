#include "RadioBox.h"

RadioBox::RadioBox(int bord, short x, short y, COORD cor, string str[])
	:Control::Control(bord, x, y, cor), currentIndex(0)
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



	int checkBoxIndex = 0;
	for (auto child : allCheckBoxes)
	{
		// checking if mouse pressed within Checkbox area
		if (y >= child->getTop() && y <= child->getTop() + child->getCord().Y)
		{
			if (x >= this->getLeft() && x <= this->getLeft() + this->getCord().X + 1)
			{
				currentIndex = checkBoxIndex;
			}
		}

		checkBoxIndex++;
		child->setIsChecked(false);//her is false because we change the new all,but the current coord get change to true
		child->mousePressed(x, y, isLeft, g);
	}
}

void RadioBox::keyDown(int keyCode, char charecter, Graphics &g)
{
	int index = 0;
	if (keyCode == 40 || keyCode == 98)		// down arrow or NUM2 key
	{
		if (currentIndex == allCheckBoxes.size() - 1)
			currentIndex = 0;
		else
			++currentIndex;
		//Control::setFocus(*this->allCheckBoxes[currentIndex]);
		//allCheckBoxes[currentIndex]->setBackGround(Color::Blue);
	}

	else if (keyCode == 38 || keyCode == 104)   // up arrow or NUM8 key
	{
		if (currentIndex == 0)
			currentIndex = allCheckBoxes.size() - 1;
		else
			--currentIndex;
		//Control::setFocus(*this->allCheckBoxes[currentIndex]);
	}

	else if (keyCode == 32 || keyCode == 13) {	// Space or Enter key
		for (auto child : allCheckBoxes)
		{
			child->setIsChecked(true);//her is true because we change the new current index
			child->keyDown(keyCode, charecter, g);
		}
		
		allCheckBoxes[currentIndex]->keyDown(keyCode, charecter, g);
		

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