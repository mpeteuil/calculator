/********************************************/
/*//  BoolOr.cc                             */
/********************************************/

#include "BoolOr.h"

BoolOr::BoolOr()
{
	
}

BoolOr::~BoolOr()
{
	//pointers are deleted in parent destructor, which is inherited
}

//virtual void accept(Visitor& )

BoolOr::BoolOr(const BoolOr& object)
{
	//empty
}

BoolOr& BoolOr::operator=(const BoolOr& d)
{
	//empty
}

void BoolOr::accept(Visitor* V)
{
	V->VisitBoolOr(this);
}
