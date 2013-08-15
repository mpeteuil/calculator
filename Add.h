/********************************************/
/*//  Add.h                                 */
/********************************************/

#ifndef ADD_
#define ADD_

#include "BinaryExpression.h"
#include "Visitor.h"
using namespace std;

class Add: public BinaryExpression
{
public:
	Add();
	Add(Expression* L, Expression* R) : BinaryExpression(L, R){};
	virtual ~Add();
  	virtual void accept(Visitor* );
private:
  	Add(const Add& object);
	Add& operator=(const Add& d);
};

#endif
