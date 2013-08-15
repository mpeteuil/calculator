/********************************************/
/*//  BinaryExpression.h                    */
/********************************************/

#ifndef BINARY_EXP_
#define BINARY_EXP_

#include "MathExpression.h"

class BinaryExpression: public MathExpression
{
public:
	BinaryExpression(Expression* L, Expression* R);
	Expression* GetRight();
	Expression* GetLeft();
	virtual ~BinaryExpression();
  	virtual void accept(Visitor* )=0;
private:
  	BinaryExpression(const BinaryExpression& object);
	BinaryExpression& operator=(const BinaryExpression& d);
protected:
  	BinaryExpression();
	Expression* binaryRight;
	Expression* binaryLeft;
};

#endif
