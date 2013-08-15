/********************************************/
/*//  GreaterEqualLess.cc                   */
/********************************************/

#include "GreaterEqualLess.h"

GreaterEqualLess::GreaterEqualLess()
{
	//empty
}

GreaterEqualLess::GreaterEqualLess(Expression* L, Expression* R)
{
	boolRight = R;
	boolLeft = L;
}

GreaterEqualLess::~GreaterEqualLess()
{
	delete boolRight;
	delete boolLeft;
}

Expression* GreaterEqualLess::GetRight()
{
	return boolRight;
}

Expression* GreaterEqualLess::GetLeft()
{
	return boolLeft;
}
