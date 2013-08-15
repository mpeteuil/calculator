#ifndef CALCULATORBUTTON_H_
#define CALCULATORBUTTON_H_

#include "FL/Fl_Button.H"
#include "Widget.h"
using namespace std;

class CalculatorButton: public Fl_Button, public Widget
{
	public:
		virtual ~CalculatorButton();
		CalculatorButton(int , int , int , int , const char *);
		static void cb_changed(Fl_Widget*, void*);
		
	private:
		CalculatorButton();
};
#endif /*CALCULATORBUTTON_H_*/
