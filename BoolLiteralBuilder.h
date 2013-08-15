/********************************************/
/*//  BoolLiteralBuilder.h                  */
/********************************************/

#ifndef BOOL_LITERAL_BUILDER_
#define BOOL_LITERAL_BUILDER_

#include "LiteralBuilder.h"
using namespace std;

class BoolLiteralBuilder: public LiteralBuilder
{
public:
  	BoolLiteralBuilder();
	BoolLiteralBuilder(bool variable);
	virtual ~BoolLiteralBuilder();
	virtual void BuildLiteral(double);
	virtual Expression* GetExpression();
private:;
  	BoolLiteralBuilder(const BoolLiteralBuilder& object);
	BoolLiteralBuilder& operator=(const BoolLiteralBuilder& d);
};

#endif
