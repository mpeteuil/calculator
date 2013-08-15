/********************************************/
/*//  Divide.h                              */
/********************************************/

#ifndef DIVIDE_
#define DIVIDE_

#include "BinaryExpression.h"
#include "Visitor.h"
using namespace std;

class Divide: public BinaryExpression
{
public:
  	Divide();
	Divide(Expression* L, Expression* R) : BinaryExpression(L, R){};
	virtual ~Divide();
  	virtual void accept(Visitor* );
private:
  	Divide(const Divide& object);
	Divide& operator=(const Divide& d);
};

#endif
