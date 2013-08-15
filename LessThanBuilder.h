/********************************************/
/*//  LessThanBuilder.h                     */
/********************************************/

#ifndef LESS_BUILDER_
#define LESS_BUILDER_

#include "BinaryExpressionBuilder.h"
using namespace std;

class LessThanBuilder: public BinaryExpressionBuilder
{
public:
	LessThanBuilder();
	virtual ~LessThanBuilder();
	virtual void BuildRight(Expression*);
	virtual void BuildLeft(Expression*);
	virtual Expression* GetExpression();
private:
  	LessThanBuilder(const LessThanBuilder& object);
	LessThanBuilder& operator=(const LessThanBuilder& d);
};

#endif
