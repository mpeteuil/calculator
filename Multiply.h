/********************************************/
/*//  Multiply.h                            */
/********************************************/

#ifndef MULTIPLY_
#define MULTIPLY_

#include "BinaryExpression.h"
#include "Visitor.h"
using namespace std;

class Multiply: public BinaryExpression
{
public:
	Multiply();
	Multiply(Expression* L, Expression* R) : BinaryExpression(L, R){};
	virtual ~Multiply();
  	virtual void accept(Visitor* );
private:
  	Multiply(const Multiply& object);
	Multiply& operator=(const Multiply& d);
};

#endif
