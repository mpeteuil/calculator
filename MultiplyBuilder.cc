/********************************************/
/*//  MultiplyBuilder.cc                    */
/********************************************/

#include "MultiplyBuilder.h"
#include "Multiply.h"
using namespace std;

MultiplyBuilder::MultiplyBuilder()
{}

MultiplyBuilder::~MultiplyBuilder()
{}

void MultiplyBuilder::BuildLeft(Expression* X)
{
	Left = X;
}

void MultiplyBuilder::BuildRight(Expression* X)
{
	Right = X;
}

Expression* MultiplyBuilder::GetExpression()
{
	return new Multiply(Left, Right);
}

MultiplyBuilder::MultiplyBuilder(const MultiplyBuilder& object)
{}

MultiplyBuilder& MultiplyBuilder::operator=(const MultiplyBuilder& d)
{}

