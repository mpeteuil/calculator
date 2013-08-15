/********************************************/
/*//  SubtractBuilder.h                     */
/********************************************/

#ifndef SUBTRACT_BUILDER_
#define SUBTRACT_BUILDER_

#include "BinaryExpressionBuilder.h"
using namespace std;

class SubtractBuilder: public BinaryExpressionBuilder
{
public:
	SubtractBuilder();
	virtual ~SubtractBuilder();
	virtual void BuildRight(Expression*);
	virtual void BuildLeft(Expression*);
	virtual Expression* GetExpression();
private:
  	SubtractBuilder(const SubtractBuilder& object);
	SubtractBuilder& operator=(const SubtractBuilder& d);
};

#endif
