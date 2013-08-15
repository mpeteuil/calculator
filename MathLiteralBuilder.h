/********************************************/
/*//  MathLiteralBuilder.h                  */
/********************************************/

#ifndef MATH_LITERAL_BUILDER_
#define MATH_LITERAL_BUILDER_

#include "LiteralBuilder.h"
using namespace std;

class MathLiteralBuilder: public LiteralBuilder
{
public:
  	MathLiteralBuilder();
	virtual ~MathLiteralBuilder();
	virtual void BuildLiteral(double);
	virtual Expression* GetExpression();
private:
  	MathLiteralBuilder(const MathLiteralBuilder& object);
	MathLiteralBuilder& operator=(const MathLiteralBuilder& d);
};

#endif
