/********************************************/
/*//  SimplifyVisitor.h                     */
/********************************************/

#ifndef SIMPLIFY_VISITOR_
#define SIMPLIFY_VISITOR_

#include "Visitor.h"
#include <iostream>
using namespace std;

class SimplifyVisitor : public Visitor
{
public:
	SimplifyVisitor();
	~SimplifyVisitor();
  	virtual void VisitMathNegate(MathNegate* );
  	virtual void VisitMathVariable(MathVariable* );
  	virtual void VisitMathLiteral(MathLiteral* );
  	virtual void VisitAdd(Add* );
  	virtual void VisitSubtract(Subtract* );
  	virtual void VisitMultiply(Multiply* );
  	virtual void VisitDivide(Divide* );
  	virtual void VisitBoolNegate(BoolNegate* );
  	virtual void VisitBoolLiteral(BoolLiteral* );
  	virtual void VisitBoolVariable(BoolVariable* );
  	virtual void VisitBoolOr(BoolOr* );
  	virtual void VisitBoolAnd(BoolAnd* );
  	virtual void VisitGreaterThan(GreaterThan* );
  	virtual void VisitLessThan(LessThan* );
  	virtual void VisitEqual(Equal* );

	Expression* GetSimple();
    
private:
	bool notEvaluatable;
	SimplifyVisitor(const SimplifyVisitor& object);
	SimplifyVisitor& operator=(const SimplifyVisitor& d);
	stack<Expression*> expressionstack;
	stack<string> stringstack;
  	
};

#endif
