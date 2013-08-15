/********************************************/
/*//  BoolAndBuilder.cc                     */
/********************************************/

#include "BoolAndBuilder.h"
#include "BoolAnd.h"
using namespace std;

BoolAndBuilder::BoolAndBuilder()
{}

BoolAndBuilder::~BoolAndBuilder()
{}

void BoolAndBuilder::BuildLeft(Expression* X)
{
	Left = X;
}

void BoolAndBuilder::BuildRight(Expression* X)
{
	Right = X;
}

Expression* BoolAndBuilder::GetExpression()
{
	return new BoolAnd(Left, Right);
}

BoolAndBuilder::BoolAndBuilder(const BoolAndBuilder& object)
{}

BoolAndBuilder& BoolAndBuilder::operator=(const BoolAndBuilder& d)
{}
