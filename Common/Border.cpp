#include "Border.h"

void Border::drawSingleBorder(int x, int y, COORD cor)
{
	drawBorder('\xDA', '\xC4', '\xBF', '\xB3', '\xC0', '\xD9', x, y, cor);
}
void Border::drawDoubleBorder(int x, int y, COORD cor)
{
	drawBorder('\xC9', '\xCD','\xBB','\xBA', '\xC8','\xBC',x,y,cor);
}

void Border::drawBorder(char topLeft, char hrLine, char topRight, char vrLine, char botoomLeft, char bottomRight, int x, int y, COORD cord)
{
	COORD c;
	c.X = x;
	c.Y = y;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	SetConsoleCursorPosition(out, { c.X, c.Y });
	for (int i = c.X; i < cord.X ; ++i)
	{
		if (i == c.X)
			cout << topLeft;
		else
			cout << hrLine;
	}
	cout << topRight;
	int v = 1;
	for (int i = c.Y; i < cord.Y; ++i)
	{	
		SetConsoleCursorPosition(out, { c.X, (SHORT)(c.Y + v) });
		cout << vrLine;
		SetConsoleCursorPosition(out, { cord.X, (SHORT)(c.Y + v)});
		cout << vrLine;
		++v;
	}
	//SetConsoleCursorPosition(out, { c.X, c.Y + 1 });
	//setCursorPosit({ this->position.X, this->position.Y + 1 }, out, info);

	//cout << vrLine;
	SetConsoleCursorPosition(out, { c.X, cord.Y});
	//setCursorPosit({ this->position.X, this->position.Y + 2 }, out, info);

	for (int i = c.X; i < cord.X; ++i)
	{
		if (i == c.X)
			cout << botoomLeft;
		else
			cout << hrLine;
	}

	cout << bottomRight;
	//SetConsoleCursorPosition(out, { c.X + ((SHORT)cord.X - c.X), c.Y + 1 });
	//setCursorPosit({ this->position.X + (SHORT)this->size, this->position.Y + 1 }, out, info);
	//cout << vrLine;
}


