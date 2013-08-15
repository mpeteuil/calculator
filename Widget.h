#ifndef WIDGET_H_
#define WIDGET_H_

#include "MediatorDirector.h"
class MediatorDirector;

class Widget
{
	public:
		void Changed();
		virtual ~Widget();
		void SetDirector(MediatorDirector* );
		Widget();
	private:
		MediatorDirector* _director;
};
#endif /*WIDGET_H_*/
