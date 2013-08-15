/********************************************/
/*//  Divide.cc                             */
/********************************************/

#include "Divide.h"

Divide::Divide()
{
	
}

Divide::~Divide()
{
	
}
Divide::Divide(const Divide& object)
{
	//empty
}

Divide& Divide::operator=(const Divide& d)
{
	//empty
}

void Divide::accept(Visitor* V)
{
	V->VisitDivide(this);
}
