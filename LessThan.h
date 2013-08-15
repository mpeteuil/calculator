/********************************************/
/*//  LessThan.h                            */
/********************************************/

#ifndef LESS_
#define LESS_

#include "GreaterEqualLess.h"
#include "Visitor.h"
using namespace std;

class LessThan: public GreaterEqualLess
{
public:
	virtual ~LessThan();
	LessThan(Expression* L, Expression* R) : GreaterEqualLess(L, R){};
  	virtual void accept(Visitor* );
private:
  	LessThan(const LessThan& object);
	LessThan& operator=(const LessThan& d);
protected:
  	LessThan();
};

#endif
