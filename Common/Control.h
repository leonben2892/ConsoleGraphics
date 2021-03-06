#pragma once
#include "Graphics.h"
#include "BorderStrategy.h"
#include <vector>

using namespace std;

class Control
{
protected:
	short left;
	short top;
	COORD cord;
	BorderStrategy *bs;
	COORD currentPosition;
	Color background, foreground;

private:
	static Control* focusObj;
	
public:
	Control();
	Control(int borderType,short x,short y, COORD cor);
	static Control* getFocus() { return focusObj; };
	static void setFocus(Control& control) { focusObj = &control; };

	void setColor(Color bg, Color fg);

	
	virtual void draw(Graphics& g, int x, int y, size_t z) {};
	virtual void mousePressed(int x, int y, bool isLeft, Graphics &g) {};
	virtual void keyDown(int keyCode, char charecter, Graphics &g) {};
	virtual short getLeft() { return left; };
	virtual short getTop() { return top; };
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return false; };
	virtual bool myPureFunction() = 0;

	virtual COORD getCord() { return cord; }
	virtual COORD getCurrentPosition() { return currentPosition; }
	virtual bool IsCursorVisible() { return false; };
	virtual bool setLocalFocus() { return false; };
	virtual Control* getCurrentFocus() { return NULL; };

	virtual void resetFocus() {};

	~Control();
};

