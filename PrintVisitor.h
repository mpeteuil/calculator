/********************************************/
/*//  PrintVisitor.h                        */
/********************************************/

#ifndef PRINT_VISITOR_
#define PRINT_VISITOR_

#include "Visitor.h"
#include <iostream>
#include <string>
using namespace std;

class PrintVisitor : public Visitor
{
public:
	PrintVisitor(){value_="";}
	~PrintVisitor();
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
  	string GetPrint();
    
private:
	string value_;
	PrintVisitor(const PrintVisitor& object);
	PrintVisitor& operator=(const PrintVisitor& d);
  	
};

#endif
