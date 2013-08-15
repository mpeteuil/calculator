/********************************************/
/*//  BoolOrBuilder.h                       */
/********************************************/

#ifndef BOOL_OR_BUILDER_
#define BOOL_OR_BUILDER_

#include "BinaryExpressionBuilder.h"
using namespace std;

class BoolOrBuilder: public BinaryExpressionBuilder
{
public:
  	BoolOrBuilder();
	virtual ~BoolOrBuilder();
	virtual void BuildRight(Expression*);
	virtual void BuildLeft(Expression*);
	virtual Expression* GetExpression();
private:
  	BoolOrBuilder(const BoolOrBuilder& object);
	BoolOrBuilder& operator=(const BoolOrBuilder& d);
};

#endif
