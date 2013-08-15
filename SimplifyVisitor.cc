/********************************************/
/*//  SimplifyVisitor.cc                    */
/********************************************/

#include "PrintVisitor.h"
#include "EvaluateVisitor.h"
#include "SimplifyVisitor.h"
#include <string>
using namespace std;

SimplifyVisitor::SimplifyVisitor()
{
	
}

SimplifyVisitor::~SimplifyVisitor()
{
	
}

void SimplifyVisitor::VisitMathNegate(MathNegate* neg)
{
	neg->GetNegate()->accept(this);
	
	Expression* negExpression = expressionstack.top();
	expressionstack.pop();	
	string negString = stringstack.top();	
	stringstack.pop();
	
	if(negString == "MathLiteral") // Check This
	{
		EvaluateVisitor* evalVisitor = new EvaluateVisitor();
		negExpression->accept(evalVisitor);

		double newNegation = evalVisitor->GetValue();
		newNegation *= -1;
		expressionstack.push(new MathLiteral(newNegation));
		stringstack.push("MathLiteral");
	}
	else
	{
		expressionstack.push(new MathNegate(negExpression));
		stringstack.push("MathNegate");
	}	
}

void SimplifyVisitor::VisitMathVariable(MathVariable* mathvar)
{
	if(mathvar->GetValueSet() == true)
	{
		expressionstack.push(new MathLiteral(mathvar->GetValue()));
		stringstack.push("MathLiteral");		
	}
	else
	{
		expressionstack.push(mathvar);
		stringstack.push("MathVariable");
	}
			
}

void SimplifyVisitor::VisitMathLiteral(MathLiteral* mathlit)
{
	expressionstack.push(mathlit);
	stringstack.push("MathLiteral");
}

void SimplifyVisitor::VisitAdd(Add* add)
{
	add->GetRight()->accept(this);
	add->GetLeft()->accept(this);
	
	Expression* addLeft = expressionstack.top();
	expressionstack.pop();	
	string addLeftString = stringstack.top();
	stringstack.pop();
	Expression* addRight = expressionstack.top();
	expressionstack.pop();
	string addRightString = stringstack.top();
	stringstack.pop();
	
	if (addLeftString == "MathLiteral" && addRightString == "MathLiteral")
	{
		double newAddition = ((MathLiteral*) addLeft)->GetValue() + ((MathLiteral*) addRight)->GetValue();
		expressionstack.push(new MathLiteral(newAddition));
		stringstack.push("MathLiteral");
	}
	else if(addLeftString != "MathLiteral" && addRightString == "MathLiteral" && (((MathLiteral*) addRight)->GetValue() == 0))
	{
		expressionstack.push(addLeft);
		stringstack.push(addLeftString);
	}
	else if(addLeftString == "MathLiteral" && (((MathLiteral*) addLeft)->GetValue() == 0) && addRightString 
!= "MathVariable")
	{
		expressionstack.push(addRight);
		stringstack.push(addRightString);
	}
	else
	{
		expressionstack.push(new Add(addLeft, addRight));
		stringstack.push("Add");
	}
}
	

void SimplifyVisitor::VisitSubtract(Subtract* sub)
{
	sub->GetRight()->accept(this);
	sub->GetLeft()->accept(this);
	
	Expression* subLeft = expressionstack.top();
	expressionstack.pop();	
	string subLeftString = stringstack.top();
	stringstack.pop();
	Expression* subRight = expressionstack.top();
	expressionstack.pop();
	string subRightString = stringstack.top();
	stringstack.pop();
	
	if (subLeftString == "MathLiteral" && subRightString == "MathLiteral")
	{
		double newSubtraction = ((MathLiteral*) subLeft)->GetValue() - ((MathLiteral*) subRight)->GetValue();
		expressionstack.push(new MathLiteral(newSubtraction));
		stringstack.push("MathLiteral");
	}
	else if(subLeftString != "MathLiteral" && subRightString == "MathLiteral" && (((MathLiteral*) subRight)->GetValue() == 0))
	{
		expressionstack.push(subLeft);
		stringstack.push(subLeftString);
	}
	else if(subLeftString == "MathLiteral" && (((MathLiteral*) subLeft)->GetValue() == 0) && subRightString != "MathLiteral")
	{
		expressionstack.push(subRight);
		stringstack.push(subRightString);
	}
	else
	{
		expressionstack.push(new Subtract(subLeft, subRight));
		stringstack.push("Subtract");
	}
}

void SimplifyVisitor::VisitMultiply(Multiply* mult)
{
	mult->GetRight()->accept(this);
	mult->GetLeft()->accept(this);
	
	Expression* multLeft = expressionstack.top();
	expressionstack.pop();	
	string multLeftString = stringstack.top();
	stringstack.pop();
	Expression* multRight = expressionstack.top();
	expressionstack.pop();
	string multRightString = stringstack.top();
	stringstack.pop();

	if (multLeftString == "MathLiteral" && multRightString == "MathLiteral")
	{	
		double newMultiplication = ((((MathLiteral*) multLeft)->GetValue()) * ((MathLiteral*) multRight)->GetValue());
		expressionstack.push(new MathLiteral(newMultiplication));
		stringstack.push("MathLiteral");
	}
	else if ((multLeftString != "MathLiteral" && multRightString == "MathLiteral" && (((MathLiteral*) multRight)->GetValue() == 1)))
	{
		expressionstack.push(multLeft);
		stringstack.push(multLeftString);
	}
	else if (multLeftString == "MathLiteral" && (((MathLiteral*) multLeft)->GetValue() == 1) && multRightString != "MathLiteral")
	{
		expressionstack.push(multRight);
		stringstack.push(multRightString);

	}
	else if (multLeftString != "MathLiteral" && multRightString == "MathLiteral" && (((MathLiteral*) multRight)->GetValue() == 0))
	{
		expressionstack.push(new MathLiteral(0));
		stringstack.push("MathLiteral");
	}
	else if (multLeftString == "MathLiteral" && (((MathLiteral*) multLeft)->GetValue() == 0) && multRightString != "MathLiteral")
	{
		expressionstack.push(new MathLiteral(0));
		stringstack.push("MathLiteral");
	
	}
	else
	{
		expressionstack.push(new Multiply(multLeft, multRight));
		stringstack.push("Multiply");
	}
}

void SimplifyVisitor::VisitDivide(Divide* div) //CHECK FOR ERRORS
{
	div->GetRight()->accept(this);
	div->GetLeft()->accept(this);
	
	Expression* divLeft = expressionstack.top();
	expressionstack.pop();	
	string divLeftString = stringstack.top();
	stringstack.pop();
	Expression* divRight = expressionstack.top();
	expressionstack.pop();
	string divRightString = stringstack.top();
	stringstack.pop();
	
	if (divLeftString == "MathLiteral" && divRightString == "MathLiteral")
	{
		double newDivision = ((((MathLiteral*) divLeft)->GetValue()) / ((MathLiteral*) divRight)->GetValue());
		expressionstack.push(new MathLiteral(newDivision));
		stringstack.push("MathLiteral");
	}
	else if (divLeftString == "MathLiteral" && (((MathLiteral*) divLeft)->GetValue() == 0))
	{
		expressionstack.push(new MathLiteral(0));	
		stringstack.push("MathLiteral");
	}
	else
	{
		expressionstack.push(new Divide(divLeft, divRight));
		stringstack.push("Divide");
	}
}

void SimplifyVisitor::VisitBoolNegate(BoolNegate* boolneg)
{
	boolneg->GetNegate()->accept(this);
	Expression* boolnegExpression = expressionstack.top();
	expressionstack.pop();
	string boolnegString = stringstack.top();
	stringstack.pop();
	
	if(boolnegString == "BoolLiteral")
	{
		EvaluateVisitor* evalVisitor = new EvaluateVisitor();
	
		boolnegExpression->accept(evalVisitor);

		bool newNegation = evalVisitor->GetValue();
		newNegation = !newNegation;
		expressionstack.push(new BoolLiteral(newNegation));
		stringstack.push("BoolLiteral");
	}
	else
	{
		expressionstack.push(new BoolNegate(boolnegExpression));
		stringstack.push("BoolNegate");
	}
}

void SimplifyVisitor::VisitBoolLiteral(BoolLiteral* boollit)
{
	expressionstack.push(boollit);
	stringstack.push("BoolLiteral");
}

void SimplifyVisitor::VisitBoolVariable(BoolVariable* boolvar)
{
	if(boolvar->GetValueSet() == true)
	{
		expressionstack.push(new BoolLiteral(boolvar->GetValue()));
		stringstack.push("BoolLiteral");		
	}
	else
	{
		expressionstack.push(boolvar);
		stringstack.push("BoolVariable");
	}
}

void SimplifyVisitor::VisitBoolOr(BoolOr* boolor)
{
	boolor->GetRight()->accept(this);
	boolor->GetLeft()->accept(this);
	
	Expression* boolorLeft = expressionstack.top();
	expressionstack.pop();
	string boolorLeftString = stringstack.top();
	stringstack.pop();
	Expression* boolorRight = expressionstack.top();
	expressionstack.pop();
	string boolorRightString = stringstack.top();
	stringstack.pop();

	if (boolorLeftString == "BoolLiteral" && boolorRightString == "BoolLiteral")
	{
		bool newbool = (((BoolLiteral*) boolorLeft)->GetValue()) || (((BoolLiteral*) boolorRight)->GetValue());
		expressionstack.push(new BoolLiteral(newbool));
		stringstack.push("BoolLiteral");
	}
	else if ((boolorLeftString != "BoolLiteral" && boolorRightString == "BoolLiteral" && (((BoolLiteral*) boolorRight)->GetValue() == true)))
	{
		expressionstack.push(new BoolLiteral(true));
		stringstack.push("BoolLiteral");
	}
	else if (boolorLeftString == "BoolLiteral" && (((BoolLiteral*) boolorLeft)->GetValue() == true) && boolorRightString != "BoolLiteral")
	{
		expressionstack.push(new BoolLiteral(true));
		stringstack.push("BoolLiteral");
	}
	else
	{
		expressionstack.push(new BoolOr(boolorLeft, boolorRight));
		stringstack.push("BoolOr");
	}
}

void SimplifyVisitor::VisitBoolAnd(BoolAnd* booland)
{
	booland->GetRight()->accept(this);
	booland->GetLeft()->accept(this);
	
	Expression* boolandLeft = expressionstack.top();
	expressionstack.pop();	
	string boolandLeftString = stringstack.top();
	stringstack.pop();
	Expression* boolandRight = expressionstack.top();
	expressionstack.pop();
	string boolandRightString = stringstack.top();
	stringstack.pop();

	if (boolandLeftString == "BoolLiteral" && boolandRightString == "BoolLiteral")
	{
		bool newbool = (((BoolLiteral*) boolandLeft)->GetValue()) && (((BoolLiteral*) boolandRight)->GetValue());
		expressionstack.push(new BoolLiteral(newbool));
		stringstack.push("BoolLiteral");
	}
	else if (boolandLeftString == "BoolLiteral" && ((BoolLiteral*) boolandLeft)->GetValue() == false)
	{
		expressionstack.push(new BoolLiteral(0));
		stringstack.push("BoolLiteral");
	}
	else if (boolandRightString == "BoolLiteral" && ((BoolLiteral*) boolandRight)->GetValue() == false)
	{
		expressionstack.push(new BoolLiteral(0));
		stringstack.push("BoolLiteral");
	}
	else
	{
		expressionstack.push(new BoolAnd(boolandLeft, boolandRight));
		stringstack.push("BoolAnd");
	}
}

void SimplifyVisitor::VisitGreaterThan(GreaterThan* greater)
{
	greater->GetRight()->accept(this);
	greater->GetLeft()->accept(this);
	
	Expression* greaterLeft = expressionstack.top();
	expressionstack.pop();	
	string greaterLeftString = stringstack.top();
	stringstack.pop();
	Expression* greaterRight = expressionstack.top();
	expressionstack.pop();
	string greaterRightString = stringstack.top();
	stringstack.pop();

	EvaluateVisitor* evalVisitor = new EvaluateVisitor();
	
	greaterLeft->accept(evalVisitor);
	greaterRight->accept(evalVisitor);
	
	if(greaterLeftString == "MathLiteral" && greaterRightString == "MathLiteral") // check if both literals
	{
		double leftSide = ((MathLiteral*)greaterLeft)->GetValue();
		double rightSide = ((MathLiteral*)greaterRight)->GetValue();
	
		if(leftSide > rightSide)
		{
			expressionstack.push(new BoolLiteral(1));
			stringstack.push("BoolLiteral");
		}	
		else
		{
			expressionstack.push(new BoolLiteral(0));
			stringstack.push("BoolLiteral");
		}
	}
	else
	{ 
		expressionstack.push(new GreaterThan(greaterLeft, greaterRight));
		stringstack.push("GreaterThan");
	}		
}

void SimplifyVisitor::VisitLessThan(LessThan* less)
{
	less->GetRight()->accept(this);
	less->GetLeft()->accept(this);
	
	Expression* lessLeft = expressionstack.top();
	expressionstack.pop();	
	string lessLeftString = stringstack.top();
	stringstack.pop();
	Expression* lessRight = expressionstack.top();
	expressionstack.pop();
	string lessRightString = stringstack.top();
	stringstack.pop();
	EvaluateVisitor* evalVisitor = new EvaluateVisitor();
	
	lessLeft->accept(evalVisitor);
	lessRight->accept(evalVisitor);
	
	if(lessLeftString == "MathLiteral" && lessRightString == "MathLiteral")  // Check This
	{
		double leftSide = ((MathLiteral*)lessLeft)->GetValue();
		double rightSide = ((MathLiteral*)lessRight)->GetValue();
		
		if(leftSide < rightSide)
		{
			expressionstack.push(new BoolLiteral(1));
			stringstack.push("BoolLiteral");
		}	
		else
		{
			expressionstack.push(new BoolLiteral(0));
			stringstack.push("BoolLiteral");
		}
	}
	else
	{
		expressionstack.push(new LessThan(lessLeft, lessRight));
		stringstack.push("LessThan");
	}	
}

void SimplifyVisitor::VisitEqual(Equal* eq)
{
	eq->GetRight()->accept(this);
	eq->GetLeft()->accept(this);
	
	Expression* eqLeft = expressionstack.top();
	expressionstack.pop();	
	string eqLeftString = stringstack.top();
	stringstack.pop();
	Expression* eqRight = expressionstack.top();
	expressionstack.pop();
	string eqRightString = stringstack.top();
	stringstack.pop();

	EvaluateVisitor* evalVisitor = new EvaluateVisitor();
	
	eqLeft->accept(evalVisitor);
	eqRight->accept(evalVisitor);
	
	if(eqLeftString == "MathLiteral" && eqRightString == "MathLiteral") // Check this
	{
		double leftSide = ((MathLiteral*)eqLeft)->GetValue();
		double rightSide = ((MathLiteral*)eqRight)->GetValue();
		
		if(leftSide == rightSide)
		{
			expressionstack.push(new BoolLiteral(1));
			stringstack.push("BoolLiteral");
		}	
		else
		{
			expressionstack.push(new BoolLiteral(0));
			stringstack.push("BoolLiteral");
		}
	}
	else
	{
		expressionstack.push(new Equal(eqLeft, eqRight));
		stringstack.push("Equal");
	}
}

Expression* SimplifyVisitor::GetSimple()
{
	Expression* newValue;
	
	if (expressionstack.size() > 0)
		newValue = expressionstack.top();
	else
	{
		newValue = NULL;
	}
	return newValue;
}

SimplifyVisitor::SimplifyVisitor(const SimplifyVisitor& object)
{
	//empty	
}

SimplifyVisitor& SimplifyVisitor::operator=(const SimplifyVisitor& d)
{
	//empty
}
