/********************************************/
/*//  VariableBuilder.h                     */
/********************************************/

#ifndef VARIABLE_BUILDER_
#define VARIABLE_BUILDER_

#include "ExpressionBuilder.h"
#include <string>
using namespace std;

class VariableBuilder: public ExpressionBuilder
{
public:
	VariableBuilder(string);
	VariableBuilder(string, unsigned);
	virtual ~VariableBuilder();
	virtual void BuildVariableName(string)=0;
	virtual void BuildVariableValue(double)=0;
	virtual void BuildVariableBool(bool)=0;
	virtual Expression* GetExpression()=0;
private:
  	VariableBuilder(const VariableBuilder& object);
	VariableBuilder& operator=(const VariableBuilder& d);
protected:
	bool _boolean;
	double _D;
	string _str;
	VariableBuilder();
};

#endif
