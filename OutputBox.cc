#include "OutputBox.h"
using namespace std;

//OutputBox::OutputBox(){}

OutputBox::~OutputBox()
{
	
}

OutputBox::OutputBox(int X, int Y, int W, int H, const char *L): Fl_Output(X, Y, W, H, L)
{
}
