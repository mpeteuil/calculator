/********************************************/
/*//  MathExpression.h                      */
/********************************************/

#ifndef MTH_EXPRESSION_
#define MTH_EXPRESSION_

#include "Expression.h"
using namespace std;

class MathExpression: public Expression
{
public:
	virtual ~MathExpression(); //destructor
  	virtual void accept(Visitor* )=0; //acceptance of visitor
private:
  	MathExpression(const MathExpression& object);
	MathExpression& operator=(const MathExpression& d);
protected:
  	MathExpression();
};

#endif
