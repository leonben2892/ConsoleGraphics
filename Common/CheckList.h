#include "../Common/Control.h"
#include "../Common/CheckBox.h"
#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;

class CheckList : public Control {
private:
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<CheckBox*> allCheckBoxes;
	vector<CheckBox*> selectedCheckBoxes;
	string checkBoxesValues[];

public:
	CheckList(int,short, short, COORD, string str[], short);
	bool addSelectedItem(string item);
	bool removeSelectedItem(string item);
	void draw(Graphics & g, int x, int y, size_t z);
	bool myPureFunction() { return true; };
	bool canGetFocus();
};
