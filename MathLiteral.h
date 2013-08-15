/********************************************/
/*//  MathLiteral.h                         */
/********************************************/

#ifndef MATH_LITERAL_
#define MATH_LITERAL_

#include "MathExpression.h"
#include "Visitor.h"
using namespace std;

class MathLiteral: public MathExpression
{
public:
  	MathLiteral();
	MathLiteral(double number);
	virtual ~MathLiteral();
	double GetValue();
  	virtual void accept(Visitor* );
private:
	double positiveInteger;
  	MathLiteral(const MathLiteral& object);
	MathLiteral& operator=(const MathLiteral& d);
};

#endif
