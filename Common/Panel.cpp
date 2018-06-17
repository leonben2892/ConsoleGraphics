#include "Panel.h"

Panel::Panel(int bord, short x, short y, COORD cor)
{
	borderType = bord;
	left = x;
	top = y;
	cord = cor;
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
}

void Panel::Add(Control* control) 
{
	items.push_back(control);
}


void mousePressed(int x, int y, bool isLeft) {};
void keyDown(int keyCode, char charecter) {};
short getLeft() { return 0; };
short getTop() { return 0; };
void getAllControls(vector<Control*>* controls) {};
bool canGetFocus() { return FALSE; };
