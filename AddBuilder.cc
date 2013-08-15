/********************************************/
/*//  AddBuilder.cc                         */
/********************************************/

#include <iostream>
#include "AddBuilder.h"
#include "Add.h"
using namespace std;

AddBuilder::AddBuilder()
{}

AddBuilder::~AddBuilder()
{}

void AddBuilder::BuildLeft(Expression* X)
{
	Left = X;
}

void AddBuilder::BuildRight(Expression* Y)
{
	Right = Y;
}

Expression* AddBuilder::GetExpression()
{
	return new Add(Left, Right);
}

AddBuilder::AddBuilder(const AddBuilder& object)
{}

AddBuilder& AddBuilder::operator=(const AddBuilder& d)
{}

