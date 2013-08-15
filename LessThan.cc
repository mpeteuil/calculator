/********************************************/
/*//  LessThan.cc                           */
/********************************************/

#include "LessThan.h"

LessThan::LessThan()
{
	
}

LessThan::~LessThan()
{
	
}

LessThan::LessThan(const LessThan& object)
{
	//empty
}

LessThan& LessThan::operator=(const LessThan& d)
{
	//empty
}

void LessThan::accept(Visitor* V)
{
	V->VisitLessThan(this);
}
