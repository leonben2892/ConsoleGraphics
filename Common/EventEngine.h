#pragma once

#include "Control.h"
#include <windows.h>
#include "Graphics.h"

class EventEngine
{
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(Control& c);
	virtual ~EventEngine();
private:
	void moveFocus(Control &main, Control *focused);

	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
};