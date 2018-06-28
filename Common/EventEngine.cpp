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
	vector<Control*> objects;
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
					if (f->IsCursorVisible())		// checking if current object needs cursor(TextBox)
						_graphics.setCursorVisibility(true);
					else
						_graphics.setCursorVisibility(false);

					moveFocus(c, f);	//move focus to the next object
					currentIndex++;
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
	vector<Control*> items;
	focused->getAllControls(&items);
	if (items.size() > 0)		// check if current focused Item has childs
	{
		if (focused->setLocalFocus())	// check if the focus is on the last child - if not move to the next child
			Control::setFocus(*focused);	// the focus is still the same Father Item
		else
		{	// moving to the next Item in the Panel
			main.getAllControls(&controls);
			auto it = find(controls.begin(), controls.end(), focused);
			do
				if (++it == controls.end())
					it = controls.begin();
			while (!(*it)->canGetFocus());
			Control::setFocus(**it);
		}
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