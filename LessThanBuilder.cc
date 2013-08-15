/********************************************/
/*//  LessThanBuilder.cc                    */
/********************************************/

#include "LessThanBuilder.h"
#include "LessThan.h"
using namespace std;

LessThanBuilder::LessThanBuilder()
{}

LessThanBuilder::~LessThanBuilder()
{}

void LessThanBuilder::BuildLeft(Expression* X)
{
	Left = X;
}

void LessThanBuilder::BuildRight(Expression* X)
{
	Right = X;
}

Expression* LessThanBuilder::GetExpression()
{
	return new LessThan(Left, Right);
}

LessThanBuilder::LessThanBuilder(const LessThanBuilder& object)
{}

LessThanBuilder& LessThanBuilder::operator=(const LessThanBuilder& d)
{}
