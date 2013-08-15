/********************************************/
/*//  BinaryExpressionBuilder.cc            */
/********************************************/

#include "BinaryExpressionBuilder.h"

BinaryExpressionBuilder::BinaryExpressionBuilder()
{
	//empty
}

/*BinaryExpressionBuilder::BinaryExpressionBuilder(Expression* L, Expression* R)
{
	Right = R;
	Left = L;
}*/

BinaryExpressionBuilder::~BinaryExpressionBuilder()
{
	delete Right;
	delete Left;
}
