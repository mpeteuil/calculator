/********************************************/
/*//  MathVariableBuilder.h                 */
/********************************************/

#ifndef MATH_VARIABLE_BUILDER_
#define MATH_VARIABLE_BUILDER_

#include "VariableBuilder.h"
#include <string>
using namespace std;

class MathVariableBuilder: public VariableBuilder
{
public:
  	MathVariableBuilder();
	MathVariableBuilder(string);
	MathVariableBuilder(string, double);
	virtual ~MathVariableBuilder();
	virtual void BuildVariableName(string);
	virtual void BuildVariableValue(double);
	virtual void BuildVariableBool(bool);
	virtual Expression* GetExpression();
private:
  	MathVariableBuilder(const MathVariableBuilder& object);
	MathVariableBuilder& operator=(const MathVariableBuilder& d);
};

#endif
