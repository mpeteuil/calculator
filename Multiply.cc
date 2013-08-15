/********************************************/
/*//  Multiply.cc                           */
/********************************************/

#include "Multiply.h"

Multiply::Multiply()
{
	
}

Multiply::~Multiply()
{
	
}
Multiply::Multiply(const Multiply& object)
{
	//empty
}

Multiply& Multiply::operator=(const Multiply& d)
{
	//empty
}

void Multiply::accept(Visitor* V)
{
	V->VisitMultiply(this);
}
