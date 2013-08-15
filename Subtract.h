/********************************************/
/*//  Subtract.h                            */
/********************************************/

#ifndef SUBTRACT_
#define SUBTRACT_

#include "BinaryExpression.h"
#include "Visitor.h"

using namespace std;

class Subtract: public BinaryExpression
{
public:
	Subtract();
	Subtract(Expression* L, Expression* R) : BinaryExpression(L, R){};
	virtual ~Subtract();
  	virtual void accept(Visitor* );
private:
  	Subtract(const Subtract& object);
	Subtract& operator=(const Subtract& d);
};

#endif
