#include "Widget.h"
using namespace std;

Widget::Widget(){}

Widget::~Widget()
{
	delete _director;
}

void Widget::Changed()
{
	_director->WidgetChanged(this);
}

void Widget::SetDirector(MediatorDirector* D)
{
	_director = D;
}
