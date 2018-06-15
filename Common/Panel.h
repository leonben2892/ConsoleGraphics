#include "../Common/Control.h"
#include <string>

using namespace std;

class Panel : public Control
{
private:
	vector<Control*> items;
	int currentFocus;

public:

	Panel(int , short, short, COORD);
	void setCurrentFocus(int);
	int getCurrentFocus();
	void draw(Graphics & g, int x, int y, size_t z);
	bool myPureFunction() { return true; };
};