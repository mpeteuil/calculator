#include "InputBox.h"
using namespace std;

//InputBox::InputBox(){}

InputBox::~InputBox()
{
	
}

void InputBox::cb_changed(Fl_Widget *o, void *v)
{
	((InputBox*) o)->Changed();
}

InputBox::InputBox(int X, int Y, int W, int H, const char *L): Fl_Input(X, Y, W, H, L)
{
	callback(cb_changed, this);
}
