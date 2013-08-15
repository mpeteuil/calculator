/********************************************/
/*//  BoolAnd.h                             */
/********************************************/

#ifndef BOOL_AND_
#define BOOL_AND_

#include "BoolLogical.h"
#include "Visitor.h"
using namespace std;

class BoolAnd: public BoolLogical
{
public:
  	BoolAnd();
	BoolAnd(Expression* L, Expression* R): BoolLogical(L, R){};
	virtual ~BoolAnd();
  	virtual void accept(Visitor* );
private:
  	BoolAnd(const BoolAnd& object);
	BoolAnd& operator=(const BoolAnd& d);
};

#endif
