/********************************************/
/*//  GreaterThan.h                         */
/********************************************/

#ifndef GREATER_
#define GREATER_

#include "GreaterEqualLess.h"
#include "Visitor.h"
using namespace std;

class GreaterThan : public GreaterEqualLess
{
public:
	GreaterThan();
	virtual ~GreaterThan();
	GreaterThan(Expression* L, Expression* R) : GreaterEqualLess(L, R){};
  	virtual void accept(Visitor* );
private:
  	GreaterThan(const GreaterThan& object);
	GreaterThan& operator=(const GreaterThan& d);
};

#endif
