#include <Windows.h>

using namespace std;

class Border
{
private:
	void drawBorder(char lt, char hr, char tr, char vr, char bl, char br, int x, int y, COORD cord);
public:
	void drawSingleBorder(int, int, COORD);
	void drawDoubleBorder(int, int, COORD);
};
