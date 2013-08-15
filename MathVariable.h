/********************************************/
/*//  MathVariable.h                        */
/********************************************/

#ifndef MATH_VARIABLE_
#define MATH_VARIABLE_

#include "MathExpression.h"
#include "Visitor.h"
#include <string>
using namespace std;

class MathVariable: public MathExpression
{
public:
  	MathVariable();
	MathVariable(string );
	MathVariable(string, unsigned);
	void SetValue(unsigned );
	string GetName();
	double GetValue();
	bool GetValueSet();
	virtual ~MathVariable();
  	virtual void accept(Visitor* );
private:
	string variableName;
	double positiveInteger;
	bool valueSet;
  	MathVariable(const MathVariable& object);
	MathVariable& operator=(const MathVariable& d);
};

#endif
