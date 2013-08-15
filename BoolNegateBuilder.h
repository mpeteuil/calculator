/********************************************/
/*//  BoolNegateBuilder.h                   */
/********************************************/

#ifndef BOOL_NEGATE_BUILDER_
#define BOOL_NEGATE_BUILDER_

#include "NegateBuilder.h"
using namespace std;

class BoolNegateBuilder: public NegateBuilder
{
public:
	BoolNegateBuilder();
	BoolNegateBuilder(Expression*);
	virtual ~BoolNegateBuilder();
	virtual void BuildNegate(Expression*);
	virtual Expression* GetExpression();
private:
  	BoolNegateBuilder(const BoolNegateBuilder& object);
	BoolNegateBuilder& operator=(const BoolNegateBuilder& d);
};

#endif
