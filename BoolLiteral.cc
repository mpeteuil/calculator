/********************************************/
/*//  BoolLiteral.cc                        */
/********************************************/

#include "BoolLiteral.h"

BoolLiteral::BoolLiteral()
{
	
}

BoolLiteral::BoolLiteral(bool value)
{
	boolean = value;
}

BoolLiteral::~BoolLiteral()
{
	
}

//virtual void accept(Visitor& )


BoolLiteral::BoolLiteral(const BoolLiteral& object)
{
	//empty
}

BoolLiteral& BoolLiteral::operator=(const BoolLiteral& d)
{
	//empty
}
	
bool BoolLiteral::GetValue()
{
	return boolean;
}

void BoolLiteral::accept(Visitor* V)
{
	V->VisitBoolLiteral(this);
}
