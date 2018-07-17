#include "Label.h"
#include <iostream>

Label::Label(short x, short y, string value) 
	: Control(0, x, y, { 0 ,0}), value(value) {}

string Label::getValue()
{
    return this->value;
}

void Label::setValue(string value)
{
    this->value = value;
}


void Label::draw(Graphics& g, int x, int y, size_t z)
{
	if (!z)
	{
		g.setBackground(this->background);
		g.setForeground(this->foreground);
		g.write(x, y, value);
	}
        
}

//void Label::setBackGround(Color FGcolor, Color BGcolor)
//{
//	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
//	DWORD attributes = 0;
//	switch (FGcolor)
//	{
//	case Color::Black:	break;
//	case Color::Blue:	attributes |= FOREGROUND_BLUE; break;
//	case Color::Green:	attributes |= FOREGROUND_GREEN; break;
//	case Color::Red:	attributes |= FOREGROUND_RED; break;
//	case Color::Cyan:	attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN; break;
//	case Color::Purple:	attributes |= FOREGROUND_BLUE | FOREGROUND_RED; break;
//	case Color::Orange: attributes |= FOREGROUND_GREEN | FOREGROUND_RED; break;
//	case Color::White:	attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED; break;
//	}
//
//	switch (BGcolor)
//	{
//	case Color::Black:	break;
//	case Color::Blue:	attributes |= BACKGROUND_BLUE; break;
//	case Color::Green:	attributes |= BACKGROUND_GREEN; break;
//	case Color::Red:	attributes |= BACKGROUND_RED; break;
//	case Color::Cyan:	attributes |= BACKGROUND_BLUE | BACKGROUND_GREEN; break;
//	case Color::Purple:	attributes |= BACKGROUND_BLUE | BACKGROUND_RED; break;
//	case Color::Orange: attributes |= BACKGROUND_GREEN | BACKGROUND_RED; break;
//	case Color::White:	attributes |= BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED; break;
//	}
//	SetConsoleTextAttribute(out, attributes);
//}
