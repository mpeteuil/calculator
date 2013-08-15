/********************************************/
/*//  ExpressionBuilder.h                   */
/********************************************/

#ifndef EXPRESSION_BUILDER_
#define EXPRESSION_BUILDER_
#include "Expression.h"
class ExpressionBuilder
{
public:
	//virtual void BuildRight(Expression*)=0;
	//virtual void BuildLeft(Expression*)=0;
	virtual Expression* GetExpression()=0;
	virtual ~ExpressionBuilder();
private:
  	ExpressionBuilder(const ExpressionBuilder& object);
	ExpressionBuilder& operator=(const ExpressionBuilder& d);
protected:
  	ExpressionBuilder();
	Expression* Right;
	Expression* Left;
};

#endif
