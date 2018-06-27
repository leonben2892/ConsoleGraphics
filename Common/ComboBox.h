#include "../Controls/Label.h"
#include <Windows.h>
#include <iostream>

class ComboBox : public Control {
private:
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<Label*> items;
	int IsMenuOpenFlg, selectedIndex, keyPressIndex;
	void HoverElement(Graphics &g, bool Up);

public:
	ComboBox(int, short, short, COORD, vector<string> comboOptions);
	void draw(Graphics & g, int x, int y, size_t z);
	bool myPureFunction() { return true; };
	bool canGetFocus();
	void mousePressed(int x, int y, bool isLeft, Graphics &g);
	void keyDown(int keyCode, char charecter, Graphics & g);
};

