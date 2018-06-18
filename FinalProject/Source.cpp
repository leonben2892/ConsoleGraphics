#include "../Common/Graphics.h"
#include "../Controls/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/Panel.h"
//#include "../Common/CheckBox.h"
#include "../Common/TextBox.h"
#include "../Common/CheckList.h"


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
	Label l(50, 12, "Hello World");

	p.Add(&l);

	EventEngine e;
	//e.run(c);

	TextBox t(1, 40, 20, { 30,10 });
	p.Add(&t);

	CheckList cc(1, (SHORT)4, (SHORT)4, { 30,14 }, new string[3]{ "one","two","three" });
	p.Add(&cc);
	
	e.run(p);

}