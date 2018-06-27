#ifndef CHECK_BOX_H
#define CHECK_BOX_H
#include "../Common/Control.h"
#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;

class CheckBox : public Control
{
private:
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	bool IsChecked;
	string cbValue;

public:
	CheckBox(short, short, string);
	void setIsChecked(bool);
	bool getIsChecked();
	void setCbValue(string);
	string getCbValue();
	void draw(Graphics & g, int x, int y, size_t z);
	bool myPureFunction() { return true; };
	bool canGetFocus();
	void mousePressed(int x, int y, bool isLeft, Graphics &g);
	void keyDown(int keyCode, char charecter, Graphics &g);
	void setBackGround(Color FGcolor, Color BGcolor);

};


#endif // CHECK_BOX_H


