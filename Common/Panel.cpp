#include "Panel.h"

Panel::Panel(int bord, short x, short y, COORD cor)
{
	Control::borderType = bord;
	Control::left = x;
	Control::top = y;
	Control::cord = cor;
}


void Panel::setCurrentFocus(int x)
{
	currentFocus = x;
}
int Panel::getCurrentFocus()
{
	return currentFocus;
}

static Control* getFocus() { return NULL; };
static void setFocus(Control& control) {};


void Panel::draw(Graphics& g, int x, int y, size_t z)
{
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

int Panel::getItemsCount()
{
	return items.size();
}



void mousePressed(int x, int y, bool isLeft) {};
void keyDown(int keyCode, char charecter) {};
short getLeft() { return 0; };
short getTop() { return 0; };
void getAllControls(vector<Control*>* controls) {};
bool canGetFocus() { return FALSE; };
