#include "Label.h"
#include <iostream>

Label::Label(short x, short y,string value) : Control(), value(value)
{
	Control::left = x;
	Control::top = y;
}

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
        g.write(x,y,value);
}
