#include "EventEngine.h"
#include <vector>
#include <algorithm>
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
			_graphics.setCursorVisibility(true);
			redraw = false;
		}
		vector<Control*> items;
		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		switch (record.EventType)
		{
		case KEY_EVENT:
		{
			auto f = Control::getFocus();
			if (f != nullptr && record.Event.KeyEvent.bKeyDown)
			{
				auto code = record.Event.KeyEvent.wVirtualKeyCode;
				auto chr = record.Event.KeyEvent.uChar.AsciiChar;
				if (code == VK_TAB)
				{
					
					f->getAllControls(&items);
					if (items.size() > 0)
					{
						moveFocus(*f, items[currentIndex]);
						//Control::setFocus(*f);
					}				
					else
					{
						moveFocus(c, f);
						currentIndex++;
					}
						
					_graphics.setCursorVisibility(true);
				}				
				else
					f->keyDown(code, chr,_graphics);
				if (code == 38 || code == 104 || code == 98 || code == 40)
					redraw = false;
				else
					redraw = true;
			}
			break;
		}
		case MOUSE_EVENT:
		{
			auto button = record.Event.MouseEvent.dwButtonState;
			auto coord = record.Event.MouseEvent.dwMousePosition;
			auto x = coord.X - c.getLeft();
			auto y = coord.Y - c.getTop();
			if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
			{
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
	vector<Control*> items;
	focused->getAllControls(&items);
	if (items.size() > 0)
	{
		auto it = find(items.begin(), items.end(), items.front());
		do
			if (++it == items.end())
				it = items.begin();
		while (!(*it)->canGetFocus());
		Control::setFocus(**it);
	}

	else
	{
		main.getAllControls(&controls);
		auto it = find(controls.begin(), controls.end(), focused);
		do
			if (++it == controls.end())
				it = controls.begin();
		while (!(*it)->canGetFocus());
		Control::setFocus(**it);
	}
		
}