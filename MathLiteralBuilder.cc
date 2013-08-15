/********************************************/
/*//  MathLiteralBuilder.cc                 */
/********************************************/

#include "MathLiteralBuilder.h"
#include "MathLiteral.h"
using namespace std;

MathLiteralBuilder::MathLiteralBuilder()
{}

MathLiteralBuilder::~MathLiteralBuilder()
{}

void MathLiteralBuilder::BuildLiteral(double D)
{
	_D = D;
}

Expression* MathLiteralBuilder::GetExpression()
{
	return new MathLiteral(_D);
}

MathLiteralBuilder::MathLiteralBuilder(const MathLiteralBuilder& object)
{}

MathLiteralBuilder& MathLiteralBuilder::operator=(const MathLiteralBuilder& d)
{}
