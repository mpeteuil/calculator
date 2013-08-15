#ifndef MEDIATOR_DIRECTOR_H_
#define MEDIATOR_DIRECTOR_H_

#include <string>
#include "Widget.h"
using namespace std;

class Widget;
class CalculatorButton;
class InputBox;
class OutputBox;

class MediatorDirector
{
	public:
		MediatorDirector();
		//MediatorDirector(int , int , int , int , const char* );
		virtual void WidgetChanged(Widget* )=0;
	protected:
		string inputString;
};
#endif /*DIRECTOR_H_*/
