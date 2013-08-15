/********************************************/
/*//  Expression.h                          */
/********************************************/

#ifndef EXPRESSION_
#define EXPRESSION_

#include <string>
#include <stack>
#include "RCObject.h"
using namespace std;

class Visitor;

class Expression : public RCObject
{
public:
	virtual ~Expression();
  	virtual void accept(Visitor* )=0;
private:
  	Expression(const Expression& object);
	Expression& operator=(const Expression& d);
protected:
	Expression();
};

#endif
