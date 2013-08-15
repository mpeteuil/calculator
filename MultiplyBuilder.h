/********************************************/
/*//  MultiplyBuilder.h                     */
/********************************************/

#ifndef MULTIPLY_BUILDER_
#define MULTIPLY_BUILDER_

#include "BinaryExpressionBuilder.h"
using namespace std;

class MultiplyBuilder: public BinaryExpressionBuilder
{
public:
	MultiplyBuilder();
	virtual ~MultiplyBuilder();
	virtual void BuildRight(Expression*);
	virtual void BuildLeft(Expression*);
	virtual Expression* GetExpression();
private:
  	MultiplyBuilder(const MultiplyBuilder& object);
	MultiplyBuilder& operator=(const MultiplyBuilder& d);
};

#endif
