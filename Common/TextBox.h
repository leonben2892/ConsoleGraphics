#include <string>
#include <Windows.h>
#include "Control.h"

using namespace std;

class TextBox : public Control
{
private:
	string text;

public:
	TextBox(int bord,short x, short y, COORD cord);
	string getValue() { return text; }
	string setValue(string s) { this->text = s; }
	void draw(Graphics& g, int x, int y, size_t z);
	bool myPureFunction() { return true; };

	bool canGetFocus();
	void mousePressed(int x, int y, bool isLeft, Graphics &g);
	void keyDown(int keyCode, char charecter, Graphics& g);
	COORD getCurrentPosition();

	bool IsCursorVisible();
};