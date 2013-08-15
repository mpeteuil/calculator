/********************************************/
/*//  BoolAnd.cc                             */
/********************************************/

#include "BoolAnd.h"

BoolAnd::BoolAnd()
{
	
}

BoolAnd::~BoolAnd()
{
	//pointers are deleted in parent destructor, which is inherited
}

//virtual void accept(Visitor& )

BoolAnd::BoolAnd(const BoolAnd& object)
{
	//empty
}

BoolAnd& BoolAnd::operator=(const BoolAnd& d)
{
	//empty
}

void BoolAnd::accept(Visitor* V)
{
	V->VisitBoolAnd(this);
}
