/********************************************/
/*//  GreaterThanBuilder.h                  */
/********************************************/

#ifndef GREATER_BUILDER_
#define GREATER_BUILDER_

#include "BinaryExpressionBuilder.h"
using namespace std;

class GreaterThanBuilder : public BinaryExpressionBuilder
{
public:
	GreaterThanBuilder();
	virtual ~GreaterThanBuilder();
	virtual void BuildRight(Expression*);
	virtual void BuildLeft(Expression*);
	virtual Expression* GetExpression();
private:
  	GreaterThanBuilder(const GreaterThanBuilder& object);
	GreaterThanBuilder& operator=(const GreaterThanBuilder& d);
};

#endif
