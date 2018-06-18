#include "../Common/Control.h"
#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;

class Button : public Control {
private:
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	string btnValue;

public:
	Button(int, short, short, COORD, string);
	void setBtnValue(string);
	string getBtnValue();
	void draw(Graphics & g, int x, int y, size_t z);
	bool myPureFunction() { return true; };
	bool canGetFocus();
};
