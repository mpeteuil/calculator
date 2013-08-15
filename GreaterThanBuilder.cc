/********************************************/
/*//  GreaterThanBuilder.cc                 */
/********************************************/

#include "GreaterThanBuilder.h"
#include "GreaterThan.h"
using namespace std;

GreaterThanBuilder::GreaterThanBuilder()
{}

GreaterThanBuilder::~GreaterThanBuilder()
{}

void GreaterThanBuilder::BuildLeft(Expression* X)
{
	Left = X;
}

void GreaterThanBuilder::BuildRight(Expression* X)
{
	Right = X;
}

Expression* GreaterThanBuilder::GetExpression()
{
	return new GreaterThan(Left, Right);
}

GreaterThanBuilder::GreaterThanBuilder(const GreaterThanBuilder& object)
{}

GreaterThanBuilder& GreaterThanBuilder::operator=(const GreaterThanBuilder& d)
{}
