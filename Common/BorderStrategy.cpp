#include "BorderStrategy.h"

void NoBorder::drawBorderType(int x, int y, COORD cor, Graphics& g) {
	this->x = x;
	this->y = y;
	this->c = cor;
}

void SingleBorder::drawBorderType(int x, int y, COORD cor, Graphics& g) {
	this->x = x;
	this->y = y;
	this->c = cor;
	draw('\xDA', '\xC4', '\xBF', '\xB3', '\xC0', '\xD9', x, y, c, g);
}

void DoubleBorder::drawBorderType(int x, int y, COORD cor, Graphics& g) {
	this->x = x;
	this->y = y;
	this->c = cor;
	draw('\xC9', '\xCD', '\xBB', '\xBA', '\xC8', '\xBC', x, y, cor, g);
}

void BorderStrategy::draw(char topLeft, char hrLine, char topRight, char vrLine, char botoomLeft, char bottomRight, int x, int y, COORD cord, Graphics& g) {
	COORD c;
	c.X = x;
	c.Y = y;
	g.moveTo(c.X, c.Y);
	for (int i = 0; i < cord.X; ++i)
	{
		if (i == 0)
			cout << topLeft;
		else
			cout << hrLine;
	}
	cout << topRight;


	for (int horizontal = 1; horizontal < cord.Y; ++horizontal)
	{
		g.moveTo(c.X, (SHORT)(c.Y + horizontal));
		drawLine(vrLine);
	}

	g.moveTo(c.X, c.Y + cord.Y);

	for (int i = 0; i < cord.X; ++i)
	{
		if (i == 0)
			cout << botoomLeft;
		else
			cout << hrLine;
	}

	cout << bottomRight;
}

void BorderStrategy::drawLine(char vrLine)
{
	for (int i = 0; i < c.X; ++i)
	{
		if (i == 0 || i == c.X)
		{
			cout << vrLine;
		}

		else
		{
			cout << " ";
		}
	}
	cout << vrLine;
}
