/********************************************/
/*//  Equal.h                               */
/********************************************/

#ifndef EQUAL_
#define EQUAL_

#include "GreaterEqualLess.h"
#include "Visitor.h"
using namespace std;

class Equal: public GreaterEqualLess
{
public:
	virtual ~Equal();
	Equal(Expression* L, Expression* R) : GreaterEqualLess(L, R){};
  	virtual void accept(Visitor* );
private:
  	Equal(const Equal& object);
	Equal& operator=(const Equal& d);
protected:
  	Equal();
};

#endif
