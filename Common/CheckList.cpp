#include "CheckList.h"

CheckList::CheckList(int bord, short x, short y, COORD cor, string str[]) 
	:Control::Control(bord,x,y,cor) , currentIndex(0)
{
	for (short i = 0; i < (short)str->size(); i++) 
	{
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
	int index = 0;
	if (keyCode == 40 || keyCode == 98)		// down arrow or NUM2 key
	{
		if (currentIndex == allCheckBoxes.size() -1)
			currentIndex = 0;
		else
			++currentIndex;
		//Control::setFocus(*this->allCheckBoxes[currentIndex]);
		allCheckBoxes[currentIndex]->setBackGround(Color::Blue);
	}

	else if (keyCode == 38 || keyCode == 104)   // up arrow or NUM8 key
	{	
		if (currentIndex == 0)
			currentIndex = allCheckBoxes.size() -1;
		else
			--currentIndex;
		//Control::setFocus(*this->allCheckBoxes[currentIndex]);
	}
		
	else if (keyCode == 32 || keyCode == 13)	// Space or Enter key
		allCheckBoxes[currentIndex]->keyDown(keyCode, charecter, g);
}


bool CheckList::addSelectedItem(string item)
{
	for (auto it = allCheckBoxes.begin(); it != allCheckBoxes.end(); ) {
		if ((*it)->getCbValue() == item)
		{
			(*it)->setIsChecked(true);
			return true;
		}
		else
			++it;
	}
	return false;
	
}
bool CheckList::removeSelectedItem(string item)
{
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

