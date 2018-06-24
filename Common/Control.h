#pragma once
#include "Graphics.h"
#include "Border.h"
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

private:
	static Control* focusObj;
	
public:
	Control();
	Control(int borderType,short x,short y, COORD cor);
	static Control* getFocus() { return focusObj; };
	static void setFocus(Control& control) { focusObj = &control; };
	
	virtual void draw(Graphics& g, int x, int y, size_t z) {};
	virtual void mousePressed(int x, int y, bool isLeft, Graphics &g) {};
	virtual void keyDown(int keyCode, char charecter, Graphics &g) {};
	virtual short getLeft() { return left; };
	virtual short getTop() { return top; };
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };
	virtual bool myPureFunction() = 0;

	virtual COORD getCord() { return cord; }
	virtual COORD getCurrentPosition() { return currentPosition; }

	~Control();
};

