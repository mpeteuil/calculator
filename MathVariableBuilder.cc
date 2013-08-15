/********************************************/
/*//  MathVariableBuilder.cc                */
/********************************************/

#include "MathVariableBuilder.h"
#include "MathVariable.h"
#include <string>
using namespace std;

MathVariableBuilder::MathVariableBuilder()
{}

MathVariableBuilder::MathVariableBuilder(string)
{}

MathVariableBuilder::MathVariableBuilder(string, double)
{}

void MathVariableBuilder::BuildVariableName(string S)
{
	_str = S;
}

void MathVariableBuilder::BuildVariableValue(double D)
{
	_D = D;
}

void MathVariableBuilder::BuildVariableBool(bool B)
{
	_boolean = B;
}

Expression* MathVariableBuilder::GetExpression()
{
	Expression* MathVarGetExp;
	
	if (_boolean)
		MathVarGetExp = new MathVariable(_str, _D);
	else
		MathVarGetExp = new MathVariable(_str);
		
	return MathVarGetExp;
}

MathVariableBuilder::~MathVariableBuilder()
{}

MathVariableBuilder::MathVariableBuilder(const MathVariableBuilder& object)
{}

MathVariableBuilder& MathVariableBuilder::operator=(const MathVariableBuilder& d)
{}
