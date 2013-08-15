/********************************************/
/*//  BoolLiteralBuilder.cc                 */
/********************************************/

#include "BoolLiteralBuilder.h"
#include "BoolLiteral.h"
using namespace std;

BoolLiteralBuilder::BoolLiteralBuilder()
{}

BoolLiteralBuilder::BoolLiteralBuilder(bool variable)
{}

BoolLiteralBuilder::~BoolLiteralBuilder()
{}

void BoolLiteralBuilder::BuildLiteral(double D)
{
	_D = D;
}

Expression* BoolLiteralBuilder::GetExpression()
{
	return new BoolLiteral(_D);
}

//bool BoolLiteralBuilder::GetValue()
//{}

BoolLiteralBuilder::BoolLiteralBuilder(const BoolLiteralBuilder& object)
{}

BoolLiteralBuilder& BoolLiteralBuilder::operator=(const BoolLiteralBuilder& d)
{}
