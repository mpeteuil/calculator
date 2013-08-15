/********************************************/
/*//  NegateBuilder.h                       */
/********************************************/

#ifndef NEGATE_BUILDER_
#define NEGATE_BUILDER_

#include "ExpressionBuilder.h"
using namespace std;

class NegateBuilder: public ExpressionBuilder
{
public:
  	NegateBuilder();
	virtual ~NegateBuilder();
	virtual void BuildNegate(Expression*)=0;
	virtual Expression* GetExpression()=0;
private:
  	NegateBuilder(const NegateBuilder& object);
	NegateBuilder& operator=(const NegateBuilder& d);
protected:
	Expression *_neg;
};

#endif
