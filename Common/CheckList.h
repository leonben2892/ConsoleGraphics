//#include "../Common/Control.h"
#include "../Common/CheckBox.h"
//#include <string>
//#include <Windows.h>
//#include <iostream>

//using namespace std;

class CheckList : public Control {
private:
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<CheckBox*> allCheckBoxes;
	int currentIndex;
	//vector<CheckBox*> selectedCheckBoxes;
	//string checkBoxesValues[];

public:
	CheckList(int bordertype,short left, short top, COORD cord, string str[]);
	bool addSelectedItem(string item);
	bool removeSelectedItem(string item);
	void draw(Graphics & g, int x, int y, size_t z);
	bool myPureFunction() { return true; };
	bool canGetFocus();

	void mousePressed(int x, int y, bool isLeft, Graphics &g);
	void keyDown(int keyCode, char charecter, Graphics &g);
};
