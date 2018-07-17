#include "BorderStrategy.h"

void NoBorder::drawBorderType(int x, int y, COORD cor) {
	this->x = x;
	this->y = y;
	this->c = cor;
}

void SingleBorder::drawBorderType(int x, int y, COORD cor) {
	this->x = x;
	this->y = y;
	this->c = cor;
	draw('\xDA', '\xC4', '\xBF', '\xB3', '\xC0', '\xD9', x, y, c);
}

void DoubleBorder::drawBorderType(int x, int y, COORD cor) {
	this->x = x;
	this->y = y;
	this->c = cor;
	draw('\xC9', '\xCD', '\xBB', '\xBA', '\xC8', '\xBC', x, y, cor);
}

void BorderStrategy::draw(char topLeft, char hrLine, char topRight, char vrLine, char botoomLeft, char bottomRight, int x, int y, COORD cord) {
	COORD c;
	c.X = x;
	c.Y = y;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	SetConsoleCursorPosition(out, { c.X, c.Y });
	for (int i = 0; i < cord.X; ++i)
	{
		if (i == 0)
			cout << topLeft;
		else
			cout << hrLine;
	}
	cout << topRight;
	int v = 1;
	for (int i = 0; i < cord.Y; ++i)
	{
		SetConsoleCursorPosition(out, { c.X, (SHORT)(c.Y + v) });
		cout << vrLine;

		/* here we need to draw the background*/

		SetConsoleCursorPosition(out, { c.X + cord.X, (SHORT)(c.Y + v) });
		cout << vrLine;
		++v;
	}

	SetConsoleCursorPosition(out, { c.X, c.Y + cord.Y });

	for (int i = 0; i < cord.X; ++i)
	{
		if (i == 0)
			cout << botoomLeft;
		else
			cout << hrLine;
	}

	cout << bottomRight;
}
