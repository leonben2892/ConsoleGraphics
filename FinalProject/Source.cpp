#include "../Common/Graphics.h"
//#include "../Controls/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/Panel.h"
#include "../Common/TextBox.h"
#include "../Common/CheckList.h"
//#include "../Common/Button.h"
#include "../Common/Message_Box.h"
#include "../Common/ComboBox.h"
#include "../Common/NumericBox.h"
#include "../Common/RadioBox.h"




//class Form : public Panel
//{
//
//	CheckBox tb;
//	Label l;
//
//public:
//	Form()
//	{
//		string value("Enter Name:");
//		l.setValue(value);
//		//l.setTop(1);
//		//l.setLeft(1);
//
//		Add(l);
//		
//		//tb.setWidth(10);
//		//tb.setTop(1);
//		//tb.setLeft(1 + (short)value.size() + 1);
//		Add(tb);
//	}
//};



int main(int argc, char** argv)
{
	Panel p(2, 0, 0, { 80,50 });
	//Label l(50, 12, "Hello World");

	//p.Add(&l);

	EventEngine e;


	Button btn(1, 40, 35, { 8,2 }, "Button");
	p.Add(&btn);

	TextBox t(1, 40, 20, { 30,5 });
	p.Add(&t);
	
	CheckList cc(1, (short)4, (short)4, { 30,14 }, { "one","two","three" });
	p.Add(&cc);
	
	RadioBox rc(1, (short)4, (short)20, { 30,14 }, { "optionOne","optionTwo","optionThree" });
	p.Add(&rc);

	ComboBox cb(1, 10, 35, { 10,2 }, { "one","two","three" });
	p.Add(&cb);

	Message_Box mb(1, 45, 4, { 30,8 }, "This is a message box!!!");
	p.Add(&mb);

	NumericBox n(1, 30, 40, { 30,3 }, 5);
	p.Add(&n);

	e.run(p);

}