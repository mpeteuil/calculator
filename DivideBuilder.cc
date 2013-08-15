/********************************************/
/*//  DivideBuilder.cc                      */
/********************************************/

#include "DivideBuilder.h"
#include "Divide.h"
using namespace std;

DivideBuilder::DivideBuilder()
{}

DivideBuilder::~DivideBuilder()
{}

void DivideBuilder::BuildLeft(Expression* X)
{
	Left = X;
}

void DivideBuilder::BuildRight(Expression* X)
{
	Right = X;
}

Expression* DivideBuilder::GetExpression()
{
	return new Divide(Left, Right);
}

DivideBuilder::DivideBuilder(const DivideBuilder& object)
{}

DivideBuilder& DivideBuilder::operator=(const DivideBuilder& d)
{}
