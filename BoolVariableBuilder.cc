/********************************************/
/*//  BoolVariableBuilder.cc                */
/********************************************/

#include "BoolVariableBuilder.h"
#include "BoolVariable.h"
#include <string>
using namespace std;

BoolVariableBuilder::BoolVariableBuilder()
{
}

BoolVariableBuilder::BoolVariableBuilder(string, bool)
{
}

BoolVariableBuilder::BoolVariableBuilder(string)
{
}

void BoolVariableBuilder::BuildVariableName(string S)
{
	_str = S;
}

void BoolVariableBuilder::BuildVariableValue(double D)
{
	_D = D;
}

void BoolVariableBuilder::BuildVariableBool(bool B)
{
	_boolean = B;
}

Expression* BoolVariableBuilder::GetExpression() //has multiple ways to return as "x" or "x" with a value
{
	Expression* BoolVarGetExp;
	
	if (_boolean)
		BoolVarGetExp = new BoolVariable(_str, _D);
	else
		BoolVarGetExp = new BoolVariable(_str);
		
	return BoolVarGetExp;
}

BoolVariableBuilder::~BoolVariableBuilder()
{
}

BoolVariableBuilder::BoolVariableBuilder(const BoolVariableBuilder& object)
{
}

BoolVariableBuilder& BoolVariableBuilder::operator=(const BoolVariableBuilder& d)
{
}
