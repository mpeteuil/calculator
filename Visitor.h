/********************************************/
/*//  Visitor.h                             */
/********************************************/

#ifndef VISITOR_
#define VISITOR_

#include "MathNegate.h"
#include "MathLiteral.h"
#include "MathVariable.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "BoolNegate.h"
#include "BoolLiteral.h"
#include "BoolVariable.h"
#include "BoolOr.h"
#include "BoolAnd.h"
#include "GreaterThan.h"
#include "LessThan.h"
#include "Equal.h"


class MathNegate;
class MathLiteral;
class MathVariable;
class Add;
class Subtract;
class Multiply;
class Divide;
class BoolNegate;
class BoolLiteral;
class BoolVariable;
class BoolOr;
class BoolAnd;
class GreaterThan;
class LessThan;
class Equal;

using namespace std;


/***** Define Visitor Abstract Class *****/
class Visitor
{
public:
	~Visitor();
	Visitor(); 
	virtual void VisitMathNegate(MathNegate* )=0;
	virtual void VisitMathVariable(MathVariable* )=0;
	virtual void VisitMathLiteral(MathLiteral* )=0;
  	virtual void VisitAdd(Add* )=0;
  	virtual void VisitSubtract(Subtract* )=0;
  	virtual void VisitMultiply(Multiply* )=0;
  	virtual void VisitDivide(Divide* )=0;
  	virtual void VisitBoolNegate(BoolNegate* )=0;
  	virtual void VisitBoolLiteral(BoolLiteral* )=0;
  	virtual void VisitBoolVariable(BoolVariable* )=0;
  	virtual void VisitBoolOr(BoolOr* )=0;
  	virtual void VisitBoolAnd(BoolAnd* )=0;
  	virtual void VisitGreaterThan(GreaterThan* )=0;
  	virtual void VisitLessThan(LessThan* )=0;
  	virtual void VisitEqual(Equal* )=0;
  
    
private:
  	Visitor(const Visitor& object);
	Visitor& operator=(const Visitor& d);
protected:
 	
};

#endif
