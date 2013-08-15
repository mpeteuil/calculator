/********************************************/
/*//  BoolVariable.cc                       */
/********************************************/

#include "BoolVariable.h"

BoolVariable::BoolVariable()
{
	
}

BoolVariable::BoolVariable(string name, bool B)
{
	variableName = name;
	boolean = B;
	valueSet = true;
}

BoolVariable::BoolVariable(string name)
{
	variableName = name;
	valueSet = false;
}

BoolVariable::~BoolVariable()
{
	
}


BoolVariable::BoolVariable(const BoolVariable& object)
{
	//empty
}

BoolVariable& BoolVariable::operator=(const BoolVariable& d)
{
	//empty
}

void BoolVariable::SetValue(bool B)
{
	boolean = B;
}

string BoolVariable::GetName()
{
	return variableName;
}

bool BoolVariable::GetValue()
{
	return boolean;
}

bool BoolVariable::GetValueSet()
{
	return valueSet;
}

void BoolVariable::accept(Visitor* V)
{
	V->VisitBoolVariable(this);
}
