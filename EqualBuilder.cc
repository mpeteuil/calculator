/********************************************/
/*//  EqualBuilder.cc                       */
/********************************************/

#include "EqualBuilder.h"
#include "Equal.h"
using namespace std;

EqualBuilder::EqualBuilder()
{}

EqualBuilder::~EqualBuilder()
{}

void EqualBuilder::BuildLeft(Expression* X)
{
	Left = X;
}

void EqualBuilder::BuildRight(Expression* X)
{
	Right = X;
}

Expression* EqualBuilder::GetExpression()
{
	return new Equal(Left, Right);
}

EqualBuilder::EqualBuilder(const EqualBuilder& object)
{}

EqualBuilder& EqualBuilder::operator=(const EqualBuilder& d)
{}
