/********************************************/
/*//  BoolLogical.h                         */
/********************************************/

#ifndef BOOL_LOGIC_
#define BOOL_LOGIC_

#include "BooleanExpression.h"
using namespace std;

class BoolLogical: public BooleanExpression
{
public:
	BoolLogical(Expression* L, Expression* R);
	Expression* GetLeft();
	Expression* GetRight();
	virtual ~BoolLogical();
  	virtual void accept(Visitor* )=0;
private:
  	BoolLogical(const BoolLogical& object);
	BoolLogical& operator=(const BoolLogical& d);
protected:
  	BoolLogical();
	Expression* boolLogicalRight;
	Expression* boolLogicalLeft;
};

#endif
