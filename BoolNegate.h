/********************************************/
/*//  BoolNegate.h                          */
/********************************************/

#ifndef BOOL_NEGATE_
#define BOOL_NEGATE_

#include "BooleanExpression.h"
#include "Visitor.h"
using namespace std;

class BoolNegate: public BooleanExpression
{
public:
	BoolNegate();
	BoolNegate(Expression*);
	virtual ~BoolNegate();
	Expression* GetNegate();
	virtual void accept(Visitor* );
private:
  	BoolNegate(const BoolNegate& object);
	BoolNegate& operator=(const BoolNegate& d);
	Expression* boolNegatePtr;
};

#endif
