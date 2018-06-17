#include "../Common/Graphics.h"
#include "../Controls/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/Panel.h"
#include "../Common/CheckBox.h"
#include "../Common/TextBox.h"


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
	/*vector<Control*> controls;*/
	//Label l(10, 12,"Hello World");
	////Control& l2 = l;
	//EventEngine e;
	////e.run(l);

	//Panel p(2, 6, 7, { 60,30 });
	////Control& l3 = p;
	////Control& l2 = l;
	//
	//Add(&l);
	//e.run(p);


	//CheckBox newcb(10, 12, "hello");
	//Control& l4 = newcb;
	//e.run(newcb);

	Panel p(2, 0, 0, { 60,50 });
	Label l(10, 12, "Hello World");

	p.Add(&l);

	CheckBox c(14, 14,"hello");

	p.Add(&c);

	EventEngine e;
	//e.run(c);

	TextBox t(1, 20, 20, { 30,30 });
	p.Add(&t);
	
	e.run(p);

}