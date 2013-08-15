/********************************************/
/*//  MathNegate.cc                         */
/********************************************/
#include <iostream>
#include "MathNegate.h"

MathNegate::MathNegate()
{
	
}

MathNegate::MathNegate(Expression* N)
{
	mathNegatePtr = N;
}

MathNegate::~MathNegate()
{
	delete mathNegatePtr;
}

//virtual void accept(Visitor& )

MathNegate::MathNegate(const MathNegate& object)
{
	//empty
}

MathNegate& MathNegate::operator=(const MathNegate& d)
{
	//empty
}

Expression* MathNegate::GetNegate()
{
	return mathNegatePtr;
}

void MathNegate::accept(Visitor* V)
{
	if (V == NULL)
		cout << "V = NULL" << endl;
	V->VisitMathNegate(this);
}
