/********************************************/
/*//  Subtract.cc                           */
/********************************************/

#include "Subtract.h"

Subtract::Subtract()
{
	
}

Subtract::~Subtract()
{
	
}
Subtract::Subtract(const Subtract& object)
{
	//empty
}

Subtract& Subtract::operator=(const Subtract& d)
{
	//empty
}

void Subtract::accept(Visitor* V)
{
	V->VisitSubtract(this);
}
