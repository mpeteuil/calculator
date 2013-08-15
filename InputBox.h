#ifndef INPUTBOX_H_
#define INPUTBOX_H_

#include "FL/Fl_Widget.H"
#include "FL/Fl_Input.H"
#include "Widget.h"

class InputBox: public Fl_Input, public Widget
{
	public:
		virtual ~InputBox();
		InputBox(int, int, int, int, const char* );
		static void cb_changed(Fl_Widget*, void*);
	private:
		InputBox();
};
#endif /*INPUTBOX_H_*/
