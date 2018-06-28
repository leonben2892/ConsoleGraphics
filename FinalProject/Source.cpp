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
	EventEngine e;

	/*Panel view & Label: "Main Panel"*/
	Panel p(2, 0, 0, { 130,45 });

	Label mainPanelLabel(65, 1, "Main Panel");
	p.Add(&mainPanelLabel);

	/*CheckList view & Label: "CheckList"*/
	Label checkListLabel(15, 3, "CheckList");
	p.Add(&checkListLabel);

	CheckList cc(1, (short)4, (short)4, { 30,14 }, { "one","two","three" });
	p.Add(&cc);

	/*RadioBox view & Label: "RadioBox"*/
	Label radioBoxLabel(55, 3, "RadioBox");
	p.Add(&radioBoxLabel);

	RadioBox rc(1, (short)45, (short)4, { 30,14 }, { "optionOne","optionTwo","optionThree" });
	p.Add(&rc);

	/*TextBox view & Label: "TextBox"*/
	Label textBoxLabel(16, 20, "TextBox");
	p.Add(&textBoxLabel);

	TextBox t(1, 4, 21, { 30,5 });
	p.Add(&t);

	/*NumericBox view & Label: "NumericBox"*/
	Label numericBoxLabel(53, 20, "NumericBox");
	p.Add(&numericBoxLabel);

	NumericBox n(1, 50, 21, { 15,3 }, 5);
	p.Add(&n);

	/*Buttons view & Label: "Buttons"*/
	Label buttonsLabel(16, 29, "Buttons");
	p.Add(&buttonsLabel);

	Button btn1(1, 4, 31, { 8,2 }, "Button1");
	p.Add(&btn1);

	Button btn2(1, 15, 31, { 8,2 }, "Button2");
	p.Add(&btn2);

	Button btn3(1, 26, 31, { 8,2 }, "Button3");
	p.Add(&btn3);

	/*Panel view & Label: "Secondery Panel"; (Secondery Panel)*/
	Panel p2(1, 80, 3, { 48,40 });
	p.Add(&p2);

	Label seconderyPanelLabel(96, 4, "Secondery Panel");
	p2.Add(&seconderyPanelLabel);
	
	/*ComboBox view & Label: "ComboBox"; (In secondery panel)*/
	Label comboBoxLabel(84, 7, "ComboBox");
	p2.Add(&comboBoxLabel);

	ComboBox cb(1, 82, 8, { 10,2 }, { "one","two","three" });
	p2.Add(&cb);

	/*Message_Box view & Label: "MessageBox"; (In secondery panel)*/
	Label messageBoxLabel(92, 17, "MessageBox");
	p2.Add(&messageBoxLabel);

	Message_Box mb(1, 82, 18, { 30,8 }, "This is a message box!!!");
	p2.Add(&mb);

	/*RadioBox view & Label: "RadioBox"; (In secondery panel)*/
	Label radioBoxLabel2(92, 29, "RadioBox");
	p.Add(&radioBoxLabel2);

	RadioBox rc2(1, (short)82, (short)30, { 30,10 }, { "seconderyPanelOne","seconderyPanelTwo","seconderyPanelThree" });
	p2.Add(&rc2);

	e.run(p);

}