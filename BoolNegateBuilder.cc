/********************************************/
/*//  BoolNegateBuilder.cc                  */
/********************************************/

#include "BoolNegateBuilder.h"
#include "BoolNegate.h"
using namespace std;

BoolNegateBuilder::BoolNegateBuilder()
{}

BoolNegateBuilder::BoolNegateBuilder(Expression*)
{}

BoolNegateBuilder::~BoolNegateBuilder()
{}

void BoolNegateBuilder::BuildNegate(Expression* N)
{
	_neg = N;	
}

Expression* BoolNegateBuilder::GetExpression()
{
	return new BoolNegate(_neg);
}

BoolNegateBuilder::BoolNegateBuilder(const BoolNegateBuilder& object)
{}

BoolNegateBuilder& BoolNegateBuilder::operator=(const BoolNegateBuilder& d)
{}
