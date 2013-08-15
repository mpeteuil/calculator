/********************************************/
/*//  GreaterEqualLess.h                    */
/********************************************/

#ifndef GREATER_EQUAL_LESS_
#define GREATER_EQUAL_LESS_

#include "BooleanExpression.h"
using namespace std;

class GreaterEqualLess: public BooleanExpression
{
public:
	GreaterEqualLess(Expression* L, Expression* R);
	virtual ~GreaterEqualLess();
  	virtual void accept(Visitor* )=0;
	Expression* GetRight();
	Expression* GetLeft();
private:
  	GreaterEqualLess(const GreaterEqualLess& object);
	GreaterEqualLess& operator=(const GreaterEqualLess& d);
protected:
  	GreaterEqualLess();
	Expression* boolRight;
	Expression* boolLeft;
};

#endif
