/********************************************/
/*//  BoolLiteral.h                         */
/********************************************/

#ifndef BOOL_LITERAL_
#define BOOL_LITERAL_

#include "BooleanExpression.h"
#include "Visitor.h"
using namespace std;

class BoolLiteral: public BooleanExpression
{
public:
  	BoolLiteral();
	BoolLiteral(bool variable);
	virtual ~BoolLiteral();
	bool GetValue();
  	virtual void accept(Visitor* );
private:
	bool boolean;
  	BoolLiteral(const BoolLiteral& object);
	BoolLiteral& operator=(const BoolLiteral& d);
};

#endif
