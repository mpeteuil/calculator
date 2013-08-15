/********************************************/
/*//  DivideBuilder.h                       */
/********************************************/

#ifndef DIVIDE_BUILDER_
#define DIVIDE_BUILDER_

#include "BinaryExpressionBuilder.h"
using namespace std;

class DivideBuilder: public BinaryExpressionBuilder
{
public:
	DivideBuilder();
	virtual ~DivideBuilder();
	virtual void BuildRight(Expression*);
	virtual void BuildLeft(Expression*);
	virtual Expression* GetExpression();
private:
  	DivideBuilder(const DivideBuilder& object);
	DivideBuilder& operator=(const DivideBuilder& d);
};

#endif
