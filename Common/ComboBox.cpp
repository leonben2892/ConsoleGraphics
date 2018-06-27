#include "ComboBox.h"

ComboBox::ComboBox(int bord, short x, short y, COORD cor, vector<string> comboOptions) 
	: Control::Control(bord,x,y,cor) , IsMenuOpenFlg(0), selectedIndex(-1), keyPressIndex(-1), intialComboBoxValue("")
{
	for (size_t i = 0; i < comboOptions.size(); i++) {
		items.push_back(new Label((short)(x + 1), (short)(y + cord.Y + 2 + i), comboOptions[i]));
	}
}

void ComboBox::draw(Graphics & g, int x, int y, size_t z) 
{
	bs->drawBorderType(x, y, cord);
	bs->drawBorderType((short)(x + cord.X + 1), y, { 2,2 });
	if (IsMenuOpenFlg == 1)
		bs->drawBorderType(x, (short)(y + cord.Y + 1), {cord.X, (short)(cord.Y + items.size())});

	if (selectedIndex == -1)
		g.write(x+1, y+1, intialComboBoxValue);
	else
		items[selectedIndex]->draw(g, x+1, y+1, 0);
	
	g.write(x + cord.X + 1 + 1, y + 1, "\x1F");
	if (IsMenuOpenFlg == 1) {
		for (short i = 0; i < (short)items.size(); i++) {
			items[i]->draw(g, x + 1, y + cord.Y + 2 + i, 0);
		}
	}
}

bool ComboBox::canGetFocus() { return true; }

void ComboBox::mousePressed(int x, int y, bool isLeft, Graphics &g)
{
	//Check if arrow to open the items menu is pressed
	if (x >= (left + cord.X + 1) && x <= (left + cord.X + 1) + 2 && y >= top && y <= top + cord.Y) {
		if (IsMenuOpenFlg == 0) {
			IsMenuOpenFlg = 1;
			return;
		}
		if (IsMenuOpenFlg == 1) {
			IsMenuOpenFlg = 0;
			return;
		}
	}
	//Check if one of the items in the menu is pressed
	if (IsMenuOpenFlg == 1) {
		for (short i = 0; i < (short)items.size(); i++) {
				if(x >= (left+1) && x <= (left+cord.X) && y == (top + cord.Y + 2 + i)) {
					selectedIndex = i;
					IsMenuOpenFlg = 0;
			}		
		}
	}
}

void ComboBox::keyDown(int keyCode, char charecter, Graphics &g) {
	if (IsMenuOpenFlg == 1) {
		if (keyCode == 40 || keyCode == 98) {// down arrow or NUM2 key
			if (keyPressIndex == items.size() - 1)
				keyPressIndex = 0;
			else
				keyPressIndex++;
			HoverElement(g, false);
		}
		else if (keyCode == 38 || keyCode == 104) {// up arrow or NUM8 key
			if (keyPressIndex == 0)
				keyPressIndex = items.size() - 1;
			else
				keyPressIndex--;
			HoverElement(g, true);
		}
		else if (keyCode == 32 || keyCode == 13) {// Space or Enter key
			selectedIndex = keyPressIndex;
			IsMenuOpenFlg = 0;
		}
	}
}

void ComboBox::HoverElement(Graphics &g, bool Up) {

	if (Up)
	{
		if (keyPressIndex == 0)
		{
			items[keyPressIndex + 1]->setBackGround(Color::White, Color::Black);
			items[keyPressIndex + 1]->draw(g, items[keyPressIndex + 1]->getLeft(), items[keyPressIndex + 1]->getTop() , 0);
		}

		else if (keyPressIndex == items.size() - 1)
		{

			items[0]->setBackGround(Color::White, Color::Black);
			items[0]->draw(g, items[0]->getLeft(), items[0]->getTop(), 0);
		}
		else
		{
			items[keyPressIndex + 1]->setBackGround(Color::White, Color::Black);
			items[keyPressIndex + 1]->draw(g, items[keyPressIndex + 1]->getLeft(), items[keyPressIndex + 1]->getTop(), 0);
		}
	}

	else
	{
		if (keyPressIndex == 0)
		{

			items[items.size() - 1]->setBackGround(Color::White, Color::Black);
			items[items.size() - 1]->draw(g, items[items.size() - 1]->getLeft(), items[items.size() - 1]->getTop(), 0);

		}

		else if (keyPressIndex == items.size() - 1)
		{
			items[keyPressIndex - 1]->setBackGround(Color::White, Color::Black);
			items[keyPressIndex - 1]->draw(g, items[keyPressIndex - 1]->getLeft(), items[keyPressIndex - 1]->getTop(), 0);
		}
		else
		{
			items[keyPressIndex - 1]->setBackGround(Color::White, Color::Black);
			items[keyPressIndex - 1]->draw(g, items[keyPressIndex - 1]->getLeft(), items[keyPressIndex - 1]->getTop(), 0);
		}
	}


	items[keyPressIndex]->setBackGround(Color::Black, Color::White);
	items[keyPressIndex]->draw(g, items[keyPressIndex]->getLeft(), items[keyPressIndex]->getTop() , 0);
}
