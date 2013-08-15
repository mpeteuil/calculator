/********************************************/
/*//  BinaryExpressionBuilder.h             */
/********************************************/

#ifndef BINARY_EXPRESSION_BUILDER_
#define BINARY_EXPRESSION_BUILDER_

#include "ExpressionBuilder.h"

class BinaryExpressionBuilder: public ExpressionBuilder
{
public:
	virtual void BuildRight(Expression*)=0;
	virtual void BuildLeft(Expression*)=0;
	virtual Expression* GetExpression()=0;
	virtual ~BinaryExpressionBuilder();
private:
  	BinaryExpressionBuilder(const BinaryExpressionBuilder& object);
	BinaryExpressionBuilder& operator=(const BinaryExpressionBuilder& d);
protected:
  	BinaryExpressionBuilder();
	Expression* Right;
	Expression* Left;
};

#endif
