#include "RadioBox.h"

RadioBox::RadioBox(int bord, short x, short y, COORD cor, vector<string> str)
	:Control::Control(bord, x, y, cor), currentIndex(0)
{
	for (int i = 0; i < str.size(); i++) 
	{
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
	switch (keyCode)
	{
	case 40:	//down arrow 
		if (currentIndex == allCheckBoxes.size() - 1)
			currentIndex = 0;
		else
			++currentIndex;
		//Control::setFocus(*this->allCheckBoxes[currentIndex]);
		//allCheckBoxes[currentIndex]->setBackGround(Color::Blue);
		break;

	case 98:	//NUM2 key
		if (currentIndex == allCheckBoxes.size() - 1)
			currentIndex = 0;
		else
			++currentIndex;
		//Control::setFocus(*this->allCheckBoxes[currentIndex]);
		//allCheckBoxes[currentIndex]->setBackGround(Color::Blue);
		break;
	case 38:	// up arrow key
		if (currentIndex == 0)
			currentIndex = allCheckBoxes.size() - 1;
		else
			--currentIndex;
		//Control::setFocus(*this->allCheckBoxes[currentIndex]);
		break;

	case 104:	// NUM8 key
		if (currentIndex == 0)
			currentIndex = allCheckBoxes.size() - 1;
		else
			--currentIndex;
		//Control::setFocus(*this->allCheckBoxes[currentIndex]);
		break;

	case 32:	// Space key
		for (auto child : allCheckBoxes)
		{
			child->setIsChecked(true);//her is true because we change the new current index
			child->keyDown(keyCode, charecter, g);
		}

		allCheckBoxes[currentIndex]->keyDown(keyCode, charecter, g);
		break;
	case 13:	// Enter key
		for (auto child : allCheckBoxes)
		{
			child->setIsChecked(true);//her is true because we change the new current index
			child->keyDown(keyCode, charecter, g);
		}

		allCheckBoxes[currentIndex]->keyDown(keyCode, charecter, g);
		break;

	default:
		break;
	}
};

//void RadioBox::mouseHover(int x, int y, Graphics &g) 
//{
//
//	// checking if mouse pressed within Checkbox area
//	if (y >= this->top && y <= this->top + this->cord.Y)
//	{
//		if (x >= this->left && x <= this->left + this->cord.X + 1)
//		{
//			//this->colo
//		}
//	}
//};