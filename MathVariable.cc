/********************************************/
/*//  MathVariable.cc                       */
/********************************************/

#include "MathVariable.h"

MathVariable::MathVariable()
{
	
}

MathVariable::MathVariable(string name)
{
	variableName = name;
	valueSet = false;
}

MathVariable::MathVariable(string name, unsigned value)
{
	variableName = name;
	positiveInteger = value;
	valueSet = true;
}

MathVariable::~MathVariable()
{
	
}

MathVariable::MathVariable(const MathVariable& object)
{
	//empty
}

MathVariable& MathVariable::operator=(const MathVariable& d)
{
	//emptys
}

void MathVariable::SetValue(unsigned value)
{
	positiveInteger = value;
}

string MathVariable::GetName()
{
	return variableName;
}

double MathVariable::GetValue()
{
	return positiveInteger;
}

bool MathVariable::GetValueSet()
{
	return valueSet;
}

void MathVariable::accept(Visitor* V)
{
	V->VisitMathVariable(this);
}
