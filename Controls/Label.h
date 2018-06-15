#include "../Common/Control.h"
#include <string>


using namespace std;

class Label: public Control
{   
    private:
        string value;
    public:
        Label(short x, short y,string);
        string getValue();
        void setValue(string);
        void draw(Graphics& g, int x, int y, size_t z);
		bool myPureFunction() { return true; };
};