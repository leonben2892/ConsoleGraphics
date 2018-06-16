#include "../Common/Graphics.h"
#include "../Controls/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/Panel.h"
#include "../Common/CheckBox.h"

int main(int argc, char** argv)
{
	vector<Control*> controls;
	Label l(10, 12,"Hello World");
	//Control& l2 = l;
	EventEngine e;
	EventEngine e1;
	//e.run(l);

	Panel p(2, 6, 7, { 60,30 });
	Control& l3 = p;
	Control& l2 = l;
	controls.push_back(&l2);	
	p.getAllControls(&controls);
	e.run(p);

	//CheckBox newcb(10, 12, "hello");
	//Control& l4 = newcb;
	//e.run(newcb);


}