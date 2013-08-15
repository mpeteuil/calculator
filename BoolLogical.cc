/********************************************/
/*//  BoolLogical.cc                        */
/********************************************/

#include "BoolLogical.h"

BoolLogical::BoolLogical()
{
	
}

BoolLogical::BoolLogical(Expression* L, Expression* R)
{
	boolLogicalRight = R;
	boolLogicalLeft = L;
}

BoolLogical::~BoolLogical()
{
	delete boolLogicalRight;
	delete boolLogicalLeft;
}

BoolLogical::BoolLogical(const BoolLogical& object)
{

}

BoolLogical& BoolLogical::operator=(const BoolLogical& d)
{

}

Expression* BoolLogical::GetLeft()
{
	return boolLogicalLeft;
}

Expression* BoolLogical::GetRight()
{
	return boolLogicalRight;
}
