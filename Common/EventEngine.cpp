#include "EventEngine.h"
#include <vector>
#include <algorithm>
#include "RadioBox.h"
#include "Checklist.h"
#include "Panel.h"

using namespace std;

EventEngine::EventEngine(DWORD input, DWORD output)
	: _console(GetStdHandle(input)), _graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void EventEngine::run(Control &c)
{
	int currentIndex = 0;

	//set 1st child as focused by default
	setFirstFocus(c);

	for (bool redraw = true;;)
	{
		if (redraw)
		{
			_graphics.clearScreen();
			_graphics.setCursorVisibility(false);
			for (size_t z = 0; z < 1; ++z)
			{
				c.draw(_graphics, c.getLeft(), c.getTop(), z);
			}
			_graphics.moveTo(c.getFocus()->getCurrentPosition().X, c.getFocus()->getCurrentPosition().Y);
			redraw = false;
		}
		//vector<Control*> items;
		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		switch (record.EventType)
		{
		case KEY_EVENT:
		{
			auto f = Control::getFocus();	//get the current focused object

			if (f->IsCursorVisible())			// checking if current object needs cursor(TextBox)
				_graphics.setCursorVisibility(true);
			else
				_graphics.setCursorVisibility(false);

			if (f != nullptr && record.Event.KeyEvent.bKeyDown)
			{
				auto code = record.Event.KeyEvent.wVirtualKeyCode;
				auto chr = record.Event.KeyEvent.uChar.AsciiChar;
				if (code == VK_TAB)
				{
					if (isList(f))		// check if the item is CheckList or RadioBox
					{
						if (f->setLocalFocus()) {		//check if still can navigate inside the list
							f->keyDown(code, chr, _graphics);
						}
						else
							moveFocus(c, f);	// else- move to next object
					}				
					else
					{
						moveFocus(c, f);	//move focus to the next object
						currentIndex++;
					}
					
				}
				else
					f->keyDown(code, chr, _graphics);
				if (code == 38 || code == 104 || code == 98 || code == 40)
					redraw = false;
				else
				{
					_graphics.setBackground(Color::Black);
					redraw = true;
				}

			}
			break;
		}
		case MOUSE_EVENT:
		{
			_graphics.setBackground(Color::Black);
			auto button = record.Event.MouseEvent.dwButtonState;
			auto coord = record.Event.MouseEvent.dwMousePosition;
			auto x = coord.X - c.getLeft();
			auto y = coord.Y - c.getTop();
			if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
			{
				_graphics.setCursorVisibility(true);
				c.mousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED, _graphics);
				redraw = true;
			}
			break;
		}
		default:
			break;
		}
	}
}

EventEngine::~EventEngine()
{
	SetConsoleMode(_console, _consoleMode);
}

void EventEngine::moveFocus(Control &main, Control *focused)
{
	vector<Control*> controls;
	if (isPanel(focused))
	{
		if (focused->setLocalFocus())		// check if still can navigate inside the panel
		{
			Control::setFocus(*focused->getCurrentFocus());
			return;
		}

		moveFocus(*focused, focused->getCurrentFocus());
	}

	else
	{
		main.getAllControls(&controls);
		findAndSetFocusedItemInPanel(controls, focused);
	}
}

/* this function find the current object(even inside panels) and move the focus to the next object*/
void EventEngine::findAndSetFocusedItemInPanel(vector<Control*> controls,Control *focused)
{
	static int embededPanels = 0;
	vector<Control*> temp;
	auto it = focused;
	int index = 0;
	for (index; index < controls.size(); ++index)	//move over all Controls to find the current focused
	{
		if (isPanel(controls[index]))	// if its panel- recursive search
		{
			controls[index]->getAllControls(&temp);
			++embededPanels;
			findAndSetFocusedItemInPanel(temp, focused);
		}
			
		if (controls[index] == it)		// if we find the current focused
		{
			for (int i = index + 1; i < controls.size(); ++i)	// checking what is the next Item to set focus
			{
				if (controls[i]->canGetFocus()) 
				{
					if (isPanel(controls[i]))	// if the next Item is panel - set the current item inside the panel to be in focus
					{
						Control::setFocus(*controls[i]->getCurrentFocus());
					}
					else
						Control::setFocus(*controls[i]);	
					return;
				}
			}
		}
	}
	if (embededPanels == 0)		// if we get to the end of the list - setting the first focuseble item to be in focus
		setFocusInMainPanel(controls);

	else
		--embededPanels;
}

/* this function set the first focuseble Item to be in Focus*/
void EventEngine::setFocusInMainPanel(vector<Control*> controls)
{
	for (int i = 0; i < controls.size(); ++i)
	{
		if (controls[i]->canGetFocus())
		{
			Control::setFocus(*controls[i]);
			return;
		}			
	}

	Control::setFocus(*controls[0]);
}

bool EventEngine::isList(Control* control)
{
	if (dynamic_cast<RadioBox*>(control) != NULL || dynamic_cast<CheckList*>(control) != NULL)
		return true;
	return false;
}

bool EventEngine::isPanel(Control* control)
{
	if (dynamic_cast<Panel*> (control) != NULL)
		return true;
	return false;
}


void EventEngine::setFirstFocus(Control& control)
{
	vector <Control*> items;
	control.getAllControls(&items);
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i]->canGetFocus())
		{
			Control::setFocus(*items[i]);
			return;
		}
	}
}