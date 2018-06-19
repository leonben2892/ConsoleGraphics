#include "ComboBox.h"

ComboBox::ComboBox(int bord, short x, short y, COORD cor, string comboOptions[]) {
	this->borderType = bord;
	this->left = x;
	this->top = y;
	this->cord = cor;
	IsMenuOpenFlg = 0;
	for (short i = 0; i < comboOptions->size(); i++) {
		items.push_back(new Label(x+1, y+1+1*i, comboOptions[i]));
	}
}

void ComboBox::draw(Graphics & g, int x, int y, size_t z) {
	switch (borderType)
	{
	case 0:
		break;
	case 1:
		border.drawSingleBorder(x, y, cord); //Drawing main item box
		border.drawSingleBorder((short)(x + cord.X + 1), y, { 2,2 }); //Drawing arrow box to open items menu
		if(IsMenuOpenFlg == 1)
			border.drawSingleBorder(x, (short)(y + cord.Y + 1), {cord.X,(short)(cord.Y + items.size())}); //Drawing items menu
		break;
	case 2:
		border.drawDoubleBorder(x, y, cord); //Drawing main item box
		border.drawDoubleBorder((short)(x + cord.X + 1), y, { 2,2 }); //Drawing arrow box to open items menu
		if (IsMenuOpenFlg == 1)
			border.drawDoubleBorder(x, (short)(y + cord.Y + 1), { cord.X,(short)(cord.Y + items.size())}); //Drawing items menu
		break;
	default:
		break;
	}
	SetConsoleCursorPosition(out, { (short)(x +1), (short)(y + 1) });
	cout << items.at(0)->getValue();
	SetConsoleCursorPosition(out, { (short)(x+cord.X+1+1), (short)(y+1) });
	cout << '\x1F';
	if (IsMenuOpenFlg == 1) {
		for (short i = 0; i < items.size(); i++) {
			SetConsoleCursorPosition(out, { (short)(x + 1), (short)(y + cord.Y + 2 + i) });
			cout << items.at(i)->getValue();
		}
	}
}

bool ComboBox::canGetFocus() { return true; }

void ComboBox::mousePressed(int x, int y, bool isLeft)
{
	if (x >= (left + cord.X + 1) && x <= (left + cord.X + 1)+2 && y >= top && y <= top + cord.Y) {
		if (IsMenuOpenFlg == 0) {
			IsMenuOpenFlg = 1;
			return;
		}
		if (IsMenuOpenFlg == 1) {
			IsMenuOpenFlg = 0;
			return;
		}		
	}
}
