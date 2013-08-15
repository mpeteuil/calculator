/********************************************/
/*//  BoolVariable.h                        */
/********************************************/

#ifndef BOOL_VARIABLE_
#define BOOL_VARIABLE_

#include "BooleanExpression.h"
#include "Visitor.h"
#include <string>
using namespace std;

class BoolVariable: public BooleanExpression
{
public:
  	BoolVariable();
	BoolVariable(string, bool);
	BoolVariable(string);
	void SetValue(bool );
	string GetName();
	bool GetValue();
	bool GetValueSet();
	virtual ~BoolVariable();
  	virtual void accept(Visitor* );
private:
	string variableName;
	bool boolean, valueSet;
  	BoolVariable(const BoolVariable& object);
	BoolVariable& operator=(const BoolVariable& d);
};

#endif
