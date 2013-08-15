/********************************************/
/*//  MathLiteral.cc                        */
/********************************************/

#include "MathLiteral.h"

MathLiteral::MathLiteral()
{
	
}

MathLiteral::MathLiteral(double number)
{
	positiveInteger = number;
}

MathLiteral::~MathLiteral()
{
	
}

MathLiteral::MathLiteral(const MathLiteral& object)
{
	//empty
}

MathLiteral& MathLiteral::operator=(const MathLiteral& d)
{
	//empty
}

double MathLiteral::GetValue()
{
	return positiveInteger;
}

void MathLiteral::accept(Visitor* V)
{
	V->VisitMathLiteral(this);
}
