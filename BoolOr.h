/********************************************/
/*//  BoolOr.h                              */
/********************************************/

#ifndef BOOL_OR_
#define BOOL_OR_

#include "BoolLogical.h"
#include "Visitor.h"
using namespace std;

class BoolOr: public BoolLogical
{
public:
  	BoolOr();
	BoolOr(Expression* L, Expression* R): BoolLogical(L, R){};
	virtual ~BoolOr();
  	virtual void accept(Visitor* );
private:
  	BoolOr(const BoolOr& object);
	BoolOr& operator=(const BoolOr& d);
};

#endif
