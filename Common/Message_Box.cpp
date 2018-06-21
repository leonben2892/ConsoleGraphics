#include "Message_Box.h"

Message_Box::Message_Box(int bord, short x, short y, COORD cor, string str) 
	: Control(bord,x,y,cor) , messageBoxValue(str)
{
	messageBoxBtns.push_back(new Button(1, x + 1, y + cor.Y, { 8,2 }, "Cancel"));
	messageBoxBtns.push_back(new Button(1, x + 11, y + cor.Y, { 8,2 }, "OK"));
}

void Message_Box::setMessageBoxValue(string str) {
	this->messageBoxValue = str;
}

string Message_Box::getMessageBoxValue() {
	return this->messageBoxValue;
}

void Message_Box::draw(Graphics & g, int x, int y, size_t z) 
{
	bs->drawBorderType(x, y, cord);
	g.write(x + 1, y + 1, this->messageBoxValue);
	for (size_t i = 0; i < this->messageBoxBtns.size(); i++)
		this->messageBoxBtns[i]->draw(g, (short)(x + 2 + 10 * i), (short)(y + this->cord.Y - 4), z);
}

bool Message_Box::canGetFocus() { return false; }