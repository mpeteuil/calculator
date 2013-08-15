#include "CalculatorButton.h"
using namespace std;

//CalculatorButton::CalculatorButton()
//{}

CalculatorButton::~CalculatorButton()
{
	
}

void CalculatorButton::cb_changed(Fl_Widget *o, void *v)
{
	((CalculatorButton*) o)->Changed();
}

CalculatorButton::CalculatorButton(int X, int Y, int W, int H, const
char *L):Fl_Button(X, Y, W, H, L)
{
      callback(cb_changed, this);
}
