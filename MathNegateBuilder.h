/********************************************/
/*//  MathNegateBuilder.h                   */
/********************************************/

#ifndef MATH_NEGATE_BUILDER_
#define MATH_NEGATE_BUILDER_

#include "NegateBuilder.h"
using namespace std;

class MathNegateBuilder: public NegateBuilder
{
public:
  	MathNegateBuilder();
	MathNegateBuilder(Expression* );
	virtual ~MathNegateBuilder();
	virtual void BuildNegate(Expression*);
	virtual Expression* GetExpression();
private:
  	MathNegateBuilder(const MathNegateBuilder& object);
	MathNegateBuilder& operator=(const MathNegateBuilder& d);
};

#endif
