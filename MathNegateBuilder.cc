/********************************************/
/*//  MathNegateBuilder.cc                  */
/********************************************/

#include "MathNegateBuilder.h"
#include "MathNegate.h"
using namespace std;

MathNegateBuilder::MathNegateBuilder()
{}

MathNegateBuilder::MathNegateBuilder(Expression* )
{}

MathNegateBuilder::~MathNegateBuilder()
{}

void MathNegateBuilder::BuildNegate(Expression* N)
{
	_neg = 	N;
}

Expression* MathNegateBuilder::GetExpression()
{
	return new MathNegate(_neg);
}

MathNegateBuilder::MathNegateBuilder(const MathNegateBuilder& object)
{}

MathNegateBuilder& MathNegateBuilder::operator=(const MathNegateBuilder& d)
{}
