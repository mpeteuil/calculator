/********************************************/
/*//  MathNegate.h                          */
/********************************************/

#ifndef MATH_NEGATE_
#define MATH_NEGATE_

#include "MathExpression.h"
#include "Visitor.h"
using namespace std;

class MathNegate: public MathExpression
{
public:
  	MathNegate();
	MathNegate(Expression* );
	virtual ~MathNegate();
	Expression* GetNegate();
  	virtual void accept(Visitor* );
private:
  	MathNegate(const MathNegate& object);
	MathNegate& operator=(const MathNegate& d);
	Expression* mathNegatePtr;
};

#endif
