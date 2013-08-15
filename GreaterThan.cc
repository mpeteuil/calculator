/********************************************/
/*//  GreaterThan.cc                        */
/********************************************/

#include "GreaterThan.h"

GreaterThan::GreaterThan()
{
	
}

GreaterThan::~GreaterThan()
{
	
}

GreaterThan::GreaterThan(const GreaterThan& object)
{
	//empty
}

GreaterThan& GreaterThan::operator=(const GreaterThan& d)
{
	//empty
}

void GreaterThan::accept(Visitor* V)
{
	V->VisitGreaterThan(this);
}
