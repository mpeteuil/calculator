/********************************************/
/*//  AddBuilder.h                          */
/********************************************/

#ifndef ADD_BUILDER_
#define ADD_BUILDER_

#include "BinaryExpressionBuilder.h"
using namespace std;

class AddBuilder: public BinaryExpressionBuilder
{
public:
	AddBuilder();
	virtual ~AddBuilder();
	virtual void BuildRight(Expression*);
	virtual void BuildLeft(Expression*);
	virtual Expression* GetExpression();
private:
  	AddBuilder(const AddBuilder& object);
	AddBuilder& operator=(const AddBuilder& d);
};

#endif
