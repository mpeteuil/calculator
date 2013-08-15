/********************************************/
/*//  BoolOrBuilder.cc                      */
/********************************************/

#include "BoolOrBuilder.h"
#include "BoolOr.h"
using namespace std;

BoolOrBuilder::BoolOrBuilder()
{}

BoolOrBuilder::~BoolOrBuilder()
{}

void BoolOrBuilder::BuildLeft(Expression* X)
{
	Left = X;
}

void BoolOrBuilder::BuildRight(Expression* X)
{
	Right = X;
}

Expression* BoolOrBuilder::GetExpression()
{
	return new BoolOr(Left, Right);
}

BoolOrBuilder::BoolOrBuilder(const BoolOrBuilder& object)
{}

BoolOrBuilder& BoolOrBuilder::operator=(const BoolOrBuilder& d)
{}

