/********************************************/
/*//  Add.cc                                */
/********************************************/

#include "Add.h"

Add::Add()
{
	
}

Add::~Add()
{
	
}
Add::Add(const Add& object)
{
	//empty
}

Add& Add::operator=(const Add& d)
{
	//empty
}

void Add::accept(Visitor* V)
{
	V->VisitAdd(this);
}
