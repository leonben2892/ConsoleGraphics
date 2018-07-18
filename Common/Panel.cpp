#include "Panel.h"

Panel::Panel(int bord, short x, short y, COORD cor) 
	: Control(bord,x,y,cor), currentFocus(0){}


void Panel::setCurrentFocus(int x)
{
	currentFocus = x;
	Control::setFocus(*(items[x]));
}

Control* Panel::getCurrentFocus()
{
	if (!items[currentFocus]->canGetFocus())		//check if current focused item can get focus
	{
		for (currentFocus; currentFocus < items.size(); ++currentFocus)
			if (items[currentFocus]->canGetFocus())		// setting the current focus
				return items[currentFocus];
	}
	return items[currentFocus];
}


void Panel::draw(Graphics& g, int x, int y, size_t z)
{
	g.setBackground(this->background);
	g.setForeground(this->foreground);
	bs->drawBorderType(x, y, cord ,g);
	for (auto child : items)
	{
		child->draw(g, child->getLeft(), child->getTop(), z);
	}
}

void Panel::Add(Control* control) 
{
	items.push_back(control);
}

Control* Panel::GetIndex(int i)
{
	return this->items[i];
}

bool Panel::canGetFocus() 
{ 
	return true; 
}


void Panel::mousePressed(int x, int y, bool isLeft, Graphics &g)
{
	prevFocus = items[currentFocus];
	int index = 0;
	if (!isLeft)
		return;
	for (auto child : items)
	{
		if (g.isInside(x, y, child->getLeft(), child->getTop(), child->getLeft() + child->getCord().X, child->getTop() + child->getCord().Y))
		{
			if (prevFocus != child)
			{
				prevFocus->resetFocus();
			}

			child->mousePressed(x, y, isLeft, g);
			if (child->canGetFocus())
			{
				setCurrentFocus(index);
				Control::setFocus(*items[index]);
			}
				
		}		
		++index;			
	}
}

void Panel::keyDown(int keyCode, char charecter, Graphics &g)
{
	items[currentFocus]->keyDown(keyCode, charecter, g);
}

short Panel::getLeft() { return left; }
short Panel::getTop() { return top; }

void Panel::getAllControls(vector<Control*>* controls)
{
	*controls = items;
}

bool Panel::setLocalFocus()
{
	if (isList(items[currentFocus]))		// check if current focused Item is list
	{
		if (this->items[currentFocus]->setLocalFocus())
			return false;
	}

	prevFocus = items[currentFocus];

	++currentFocus;
	for ((currentFocus); currentFocus < items.size(); ++currentFocus)	// looking for the next Focuseble object
	{
		if (this->items[currentFocus]->canGetFocus())
		{
			this->setCurrentFocus(currentFocus);
			return true;
		}

	}
	currentFocus = 0;
	return false;
}


bool Panel::isList(Control* control)
{
	if (dynamic_cast<RadioBox*>(control) != NULL || dynamic_cast<CheckList*>(control) != NULL)
		return true;
	return false;
}



