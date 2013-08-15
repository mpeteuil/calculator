/********************************************/
/*//  BinaryExpression.cc                   */
/********************************************/

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression()
{
	//empty
}

BinaryExpression::BinaryExpression(Expression* L, Expression* R)
{
	binaryRight = R;
	binaryLeft = L;
	L->addRef();
	R->addRef();
}

BinaryExpression::~BinaryExpression()
{
	binaryLeft->removeRef();
	binaryRight->removeRef();
}

Expression* BinaryExpression::GetRight()
{
	return binaryRight;
}

Expression* BinaryExpression::GetLeft()
{
	return binaryLeft;
}
