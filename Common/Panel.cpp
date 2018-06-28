#include "Panel.h"

Panel::Panel(int bord, short x, short y, COORD cor) 
	: Control(bord,x,y,cor), currentFocus(0){}


void Panel::setCurrentFocus(int x)
{
	currentFocus = x;
	Control::setFocus(*items[x]);
}

int Panel::getCurrentFocus()
{
	return currentFocus;
}


void Panel::draw(Graphics& g, int x, int y, size_t z)
{
	bs->drawBorderType(x, y, cord);
	for (auto child : items)
	{
		child->draw(g, child->getLeft(), child->getTop(), z);
	}
	//g.moveTo(items[currentFocus]->getLeft()+1 , items[currentFocus]->getTop() +1);
}

void Panel::Add(Control* control) 
{
	items.push_back(control);
	Control::setFocus(*items[currentFocus]);
}

Control* Panel::GetIndex(int i)
{
	return this->items[i];
}

bool Panel::canGetFocus() { return true; }


void Panel::mousePressed(int x, int y, bool isLeft, Graphics &g)
{
	int index = 0;
	if (!isLeft)
		return;
	for (auto child : items)
	{
		if (g.isInside(x, y, child->getLeft(), child->getTop(), child->getLeft() + child->getCord().X, child->getTop() + child->getCord().Y))
		{
			child->mousePressed(x, y, isLeft, g);
			if(child->canGetFocus())
				setCurrentFocus(index);
		}		
		++index;			
	}
}

void Panel::keyDown(int keyCode, char charecter, Graphics &g)
{
	for (auto child : items)
	{
		if (child->canGetFocus())
			child->keyDown(keyCode, charecter , g);
	}
}

short Panel::getLeft() { return left; }
short Panel::getTop() { return top; }

void Panel::getAllControls(vector<Control*>* controls)
{
	*controls = items;
}

