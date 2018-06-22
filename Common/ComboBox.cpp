#include "ComboBox.h"

ComboBox::ComboBox(int bord, short x, short y, COORD cor, string comboOptions[]) 
	: Control::Control(bord,x,y,cor) , IsMenuOpenFlg(0)
{
	for (size_t i = 0; i < comboOptions->size(); i++) {
		items.push_back(new Label((short)(x + 1), (short)(y+1+1*i), comboOptions[i]));
	}
}

void ComboBox::draw(Graphics & g, int x, int y, size_t z) 
{
	bs->drawBorderType(x, y, cord);
	bs->drawBorderType((short)(x + cord.X + 1), y, { 2,2 });
	if (IsMenuOpenFlg == 1)
		bs->drawBorderType(x, (short)(y + cord.Y + 1), {cord.X, (short)(cord.Y + items.size())});

	g.write(x + 1, y + 1, items.at(0)->getValue());
	
	g.write(x + cord.X + 1 + 1, y + 1, "\x1F");
	if (IsMenuOpenFlg == 1) {
		for (short i = 0; i < (short)items.size(); i++) {
			g.write(x + 1, y + cord.Y + 2 + i, items.at(i)->getValue());
		}
	}
}

bool ComboBox::canGetFocus() { return true; }

void ComboBox::mousePressed(int x, int y, bool isLeft, Graphics &g)
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
