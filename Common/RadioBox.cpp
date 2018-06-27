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

bool RadioBox::addSelectedItem(string item) {
	for (auto it = allCheckBoxes.begin(); it != allCheckBoxes.end(); ) {
		if ((*it)->getCbValue() == item)
		{
			(*it)->setIsChecked(true);
			for (auto it2 = allCheckBoxes.begin(); it2 != allCheckBoxes.end();) {
				if ((*it2)->getCbValue() != item)
					(*it2)->setIsChecked(false);
			}
			return true;
		}
		else
			++it;
	}
	return false;
};

bool RadioBox::removeSelectedItem(string item) {
	for (auto it = allCheckBoxes.begin(); it != allCheckBoxes.end(); ) {
		if ((*it)->getCbValue() == item)
		{
			(*it)->setIsChecked(false);
			return true;
		}
		else
			++it;
	}
	return false;
}


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

		HoverElement(g, false);
		break;

	case 98:	//NUM2 key
		if (currentIndex == allCheckBoxes.size() - 1)
			currentIndex = 0;
		else
			++currentIndex;
		//Control::setFocus(*this->allCheckBoxes[currentIndex]);
		//allCheckBoxes[currentIndex]->setBackGround(Color::Blue);

		HoverElement(g, false);
		break;
	case 38:	// up arrow key
		if (currentIndex == 0)
			currentIndex = allCheckBoxes.size() - 1;
		else
			--currentIndex;
		//Control::setFocus(*this->allCheckBoxes[currentIndex]);

		HoverElement(g, true);
		break;

	case 104:	// NUM8 key
		if (currentIndex == 0)
			currentIndex = allCheckBoxes.size() - 1;
		else
			--currentIndex;
		//Control::setFocus(*this->allCheckBoxes[currentIndex]);

		HoverElement(g, true);
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

bool RadioBox::setLocalFocus()
{
	if (currentIndex == allCheckBoxes.size() - 1)
	{
		currentIndex = 0;
		return false;
	}

	++currentIndex;
	return true;
}

void RadioBox::getAllControls(vector<Control*>* controls)
{
	vector<Control*> items(allCheckBoxes.begin(), allCheckBoxes.end());
	*controls = items;
}


void RadioBox::HoverElement(Graphics &g, bool Up)
{
	if (Up)
	{
		if (currentIndex == 0)
		{
			allCheckBoxes[currentIndex + 1]->setBackGround(Color::White, Color::Black);
			allCheckBoxes[currentIndex + 1]->draw(g, allCheckBoxes[currentIndex + 1]->getLeft() + 1, allCheckBoxes[currentIndex + 1]->getTop() + 1, 1);
		}

		else if (currentIndex == allCheckBoxes.size() - 1)
		{

			allCheckBoxes[0]->setBackGround(Color::White, Color::Black);
			allCheckBoxes[0]->draw(g, allCheckBoxes[0]->getLeft() + 1, allCheckBoxes[0]->getTop() + 1, 1);
		}
		else
		{
			allCheckBoxes[currentIndex + 1]->setBackGround(Color::White, Color::Black);
			allCheckBoxes[currentIndex + 1]->draw(g, allCheckBoxes[currentIndex + 1]->getLeft() + 1, allCheckBoxes[currentIndex + 1]->getTop() + 1, 1);
		}
	}

	else
	{
		if (currentIndex == 0)
		{

			allCheckBoxes[allCheckBoxes.size() - 1]->setBackGround(Color::White, Color::Black);
			allCheckBoxes[allCheckBoxes.size() - 1]->draw(g, allCheckBoxes[allCheckBoxes.size() - 1]->getLeft() + 1, allCheckBoxes[allCheckBoxes.size() - 1]->getTop() + 1, 1);

		}

		else if (currentIndex == allCheckBoxes.size() - 1)
		{
			allCheckBoxes[currentIndex - 1]->setBackGround(Color::White, Color::Black);
			allCheckBoxes[currentIndex - 1]->draw(g, allCheckBoxes[currentIndex - 1]->getLeft() + 1, allCheckBoxes[currentIndex - 1]->getTop() + 1, 1);
		}
		else
		{
			allCheckBoxes[currentIndex - 1]->setBackGround(Color::White, Color::Black);
			allCheckBoxes[currentIndex - 1]->draw(g, allCheckBoxes[currentIndex - 1]->getLeft() + 1, allCheckBoxes[currentIndex - 1]->getTop() + 1, 1);
		}
	}


	allCheckBoxes[currentIndex]->setBackGround(Color::Black, Color::White);
	allCheckBoxes[currentIndex]->draw(g, allCheckBoxes[currentIndex]->getLeft() + 1, allCheckBoxes[currentIndex]->getTop() + 1, 1);
}