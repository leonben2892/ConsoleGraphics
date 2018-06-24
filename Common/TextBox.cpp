#include "TextBox.h"

TextBox::TextBox(int bord,short x, short y, COORD cor) 
	:Control(bord, x, y, cor) 
{
	currentPosition = { x + 1 , y + 1 };
}

void TextBox::draw(Graphics & g, int x, int y, size_t z)
{
	bs->drawBorderType(x, y, cord);
	g.write(x + 1, y + 1, this->text);
}

bool TextBox::canGetFocus() 
{ 
	return true; 
}

void TextBox::mousePressed(int x, int y, bool isLeft, Graphics &g)
{
	// checking if mouse pressed within textbox area
	if (g.isInside(x, y, left, top, left + cord.X, top + cord.Y))
	{
		if (y != currentPosition.Y)
			return;
		int s = left + text.size();
		if (x > s)		// checking if we click outside the string
		{			
			this->currentPosition = { (SHORT)(left + text.size() +1), (SHORT)y };		// moving the cursor to the end of string
			g.moveTo(currentPosition.X, currentPosition.Y);
			return;
		}
		g.moveTo(x, y);
		this->currentPosition = { (SHORT)x, (SHORT)y };
	}
		
}

void TextBox::keyDown(int keycode, char character, Graphics& g)
{
	COORD c = g.getCursorPos();
	int startstring = this->left;
	if (g.isInside(c.X, c.Y, this->left, this->top, this->left + cord.X, this->top + cord.Y))
	{
		this->currentPosition = c;
		switch (keycode)
		{
			case 8:		// backspace
				if (g.getCursorPos().X - 1 == this->left)    // if we trying to delete char but we in text border position
					return;
				//this->text.pop_back();
				text.erase(currentPosition.X - 2 - startstring,1);
				this->currentPosition = { (SHORT)(currentPosition.X - 1),(SHORT)currentPosition.Y };
				break;

			case 46:	// del key
				if (g.getCursorPos().X - 1 == this->left)    // if we trying to delete char but we in text border position
					return;
				//this->text.pop_back();
				text.erase(currentPosition.X - 1 - startstring,1);
				this->currentPosition = { (SHORT)(currentPosition.X - 1),(SHORT)currentPosition.Y };
				break;

			case 13:	// enter key
				break;

			case 37:    // left arrow
				if (currentPosition.X > left + 1)   // checking if we are not moving outside the string
					this->currentPosition = { (SHORT)currentPosition.X - 1, (SHORT)currentPosition.Y };
				break;

			case 39:	// right arrow
				if (currentPosition.X < left + cord.X - 1)   // checking if we are not moving outside the string
				{
					int s = startstring + text.size() - currentPosition.X;
					if (s >= 0)
					{
						this->currentPosition = { (SHORT)currentPosition.X + 1, (SHORT)currentPosition.Y };
					}
				}	
				break;

			default:
				int s = startstring + text.size();
				int end = left + cord.X -1;
				if (s - end < 0)
				{
					g.write((int)c.X, (int)c.Y, string(1, character));
					this->currentPosition = { (SHORT)(this->currentPosition.X + 1),(SHORT)this->currentPosition.Y };
					this->text.insert(currentPosition.X - 2 - startstring, 1, character);					
				}
				break;
				

		}	
	}	
}

COORD TextBox::getCurrentPosition() { return this->currentPosition; }