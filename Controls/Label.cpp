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