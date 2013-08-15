/********************************************/
/*//  EvaluateVisitor.h                     */
/********************************************/

#ifndef EVALUATE_VISITOR_
#define EVALUATE_VISITOR_

#include "Visitor.h"
#include <iostream>
using namespace std;

class EvaluateVisitor : public Visitor
{
public:
	EvaluateVisitor();
	~EvaluateVisitor();
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

	bool Evaluatable();
	double GetValue();
	void GetEvaluation();
    
private:
	bool notEvaluatable;
	EvaluateVisitor(const EvaluateVisitor& object);
	EvaluateVisitor& operator=(const EvaluateVisitor& d);
	stack<double> thestack;
  	
};

#endif
