/********************************************/
/*//  BoolNegate.cc                         */
/********************************************/

#include "BoolNegate.h"

BoolNegate::BoolNegate()
{
	
}

BoolNegate::BoolNegate(Expression* N)
{
	boolNegatePtr = N;
}

BoolNegate::~BoolNegate()
{
	delete boolNegatePtr;
}

//virtual void accept(Visitor& )


BoolNegate::BoolNegate(const BoolNegate& object)
{
	//empty
}

BoolNegate& BoolNegate::operator=(const BoolNegate& d)
{
	//empty
}

Expression* BoolNegate::GetNegate()
{
	return boolNegatePtr;
}

void BoolNegate::accept(Visitor* V)
{
	V->VisitBoolNegate(this);
}
