/********************************************/
/*//  EqualBuilder.h                        */
/********************************************/

#ifndef EQUAL_BUILDER_
#define EQUAL_BUILDER_

#include "BinaryExpressionBuilder.h"
using namespace std;

class EqualBuilder: public BinaryExpressionBuilder
{
public:
	EqualBuilder();
	virtual ~EqualBuilder();
	virtual void BuildRight(Expression*);
	virtual void BuildLeft(Expression*);
	virtual Expression* GetExpression();
private:
  	EqualBuilder(const EqualBuilder& object);
	EqualBuilder& operator=(const EqualBuilder& d);
};

#endif
