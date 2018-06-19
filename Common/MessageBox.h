#include "../Common/Button.h"

class Message_Box : public Control {
private:
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<Button*> messageBoxBtns;
	string messageBoxValue;

public:
	Message_Box(int, short, short, COORD, string);
	void setMessageBoxValue(string);
	string getMessageBoxValue();
	void draw(Graphics & g, int x, int y, size_t z);
	bool myPureFunction() { return true; };
	bool canGetFocus();
};
