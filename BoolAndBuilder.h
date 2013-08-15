/********************************************/
/*//  BoolAndBuilder.h                      */
/********************************************/

#ifndef BOOL_AND_BUILDER_
#define BOOL_AND_BUILDER_

#include "BinaryExpressionBuilder.h"
using namespace std;

class BoolAndBuilder: public BinaryExpressionBuilder
{
public:
  	BoolAndBuilder();
	virtual ~BoolAndBuilder();
	virtual void BuildRight(Expression*);
	virtual void BuildLeft(Expression*);
	virtual Expression* GetExpression();
private:
  	BoolAndBuilder(const BoolAndBuilder& object);
	BoolAndBuilder& operator=(const BoolAndBuilder& d);
};

#endif
