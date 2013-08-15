/********************************************/
/*//  BooleanExpression.h                   */
/********************************************/

#ifndef BOOL_EXPRESSION_
#define BOOL_EXPRESSION_

#include "Expression.h"
using namespace std;

class BooleanExpression: public Expression
{
public:
	virtual ~BooleanExpression();
  	virtual void accept(Visitor* )=0;
private:
  	BooleanExpression(const BooleanExpression& object);
	BooleanExpression& operator=(const BooleanExpression& d);
protected:
  	BooleanExpression();
};

#endif
