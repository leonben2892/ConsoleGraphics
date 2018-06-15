#include "Border.h"

void Border::drawSingleBorder(int x, int y, COORD cor)
{
	drawBorder('x\DA', 'x\C4', 'x\BF', 'x\B3', 'x\C0', 'x\D9', x, y, cor);
}
void Border::drawDoubleBorder(int x, int y, COORD cor)
{
	drawBorder('x\C9', 'x\CD','x\BB','x\BA', 'x\C8','x\BC',x,y,cor);
}

void Border::drawBorder(char lt, char hr, char tr, char vr, char bl, char br, int x, int y, COORD cord)
{

}


