/********************************************/
/*//  LiteralBuilder.h                      */
/********************************************/

#ifndef LITERAL_BUILDER_
#define LITERAL_BUILDER_

#include "ExpressionBuilder.h"
using namespace std;

class LiteralBuilder: public ExpressionBuilder
{
public:
	virtual ~LiteralBuilder();
	virtual void BuildLiteral(double)=0;
	virtual Expression* GetExpression()=0;
private:
  	LiteralBuilder(const LiteralBuilder& object);
	LiteralBuilder& operator=(const LiteralBuilder& d);
protected:
	double _D;
	LiteralBuilder();
};

#endif
