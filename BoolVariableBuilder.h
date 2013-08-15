/********************************************/
/*//  BoolVariableBuilder.h                 */
/********************************************/

#ifndef BOOL_VARIABLE_BUILDER_
#define BOOL_VARIABLE_BUILDER_

#include "VariableBuilder.h"
#include <string>
using namespace std;

class BoolVariableBuilder: public VariableBuilder
{
public:
  	BoolVariableBuilder();
	BoolVariableBuilder(string, bool);
	BoolVariableBuilder(string);
	virtual ~BoolVariableBuilder();
	virtual void BuildVariableName(string);
	virtual void BuildVariableValue(double);
	virtual void BuildVariableBool(bool);
	virtual Expression* GetExpression();
private:
  	BoolVariableBuilder(const BoolVariableBuilder& object);
	BoolVariableBuilder& operator=(const BoolVariableBuilder& d);
};

#endif
