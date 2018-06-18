#include "../Common/Button.h"

class MessageBox : public Control {
private:
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<Button*> messageBoxBtns;
	string messageBoxValue;

public:
	MessageBox(int,short,short,COORD,string);
	void setMessageBoxValue(string);
	string getMessageBoxValue();
	void draw(Graphics & g, int x, int y, size_t z);
	bool myPureFunction() { return true; };
	bool canGetFocus();
};

