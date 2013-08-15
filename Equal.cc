/********************************************/
/*//  Equal.cc                              */
/********************************************/

#include "Equal.h"

Equal::Equal()
{
	
}

Equal::~Equal()
{
	
}

Equal::Equal(const Equal& object)
{
	//empty
}

Equal& Equal::operator=(const Equal& d)
{
	//empty
}

void Equal::accept(Visitor* V)
{
	V->VisitEqual(this);
}
