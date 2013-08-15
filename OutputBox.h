#ifndef OUTPUTBOX_H_
#define OUTPUTBOX_H_

#include "FL/Fl_Output.H"
#include "Widget.h"

class OutputBox: public Fl_Output, public Widget
{
	virtual ~OutputBox();
	OutputBox(int, int, int, int, const char* );
};

#endif /*OUTPUTBOX_H_*/
