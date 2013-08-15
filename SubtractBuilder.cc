/********************************************/
/*//  SubtractBuilder.cc                    */
/********************************************/

#include "SubtractBuilder.h"
#include "Subtract.h"
using namespace std;

SubtractBuilder::SubtractBuilder()
{}

SubtractBuilder::~SubtractBuilder()
{}

void SubtractBuilder::BuildLeft(Expression* X)
{
	Left = X;
}

void SubtractBuilder::BuildRight(Expression* X)
{
	Right = X;
}

Expression* SubtractBuilder::GetExpression()
{
	return new Subtract(Left, Right);
}

SubtractBuilder::SubtractBuilder(const SubtractBuilder& object)
{}

SubtractBuilder& SubtractBuilder::operator=(const SubtractBuilder& d)
{}

