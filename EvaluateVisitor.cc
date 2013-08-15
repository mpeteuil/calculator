/********************************************/
/*//  EvaluateVisitor.cc                    */
/********************************************/

#include "EvaluateVisitor.h"

EvaluateVisitor::EvaluateVisitor()
{
	notEvaluatable = false;
}

EvaluateVisitor::~EvaluateVisitor()
{}

void EvaluateVisitor::VisitMathNegate(MathNegate* neg)
{
	neg->GetNegate()->accept(this);
	
	if (!notEvaluatable)
	{
		double temp = (-1)*(thestack.top());
		thestack.pop();
		thestack.push(temp);
	}
}

void EvaluateVisitor::VisitMathVariable(MathVariable* mathvar)
{
	if(!mathvar->GetValueSet())
		notEvaluatable = true;
	else
		thestack.push(mathvar->GetValue());	
}

void EvaluateVisitor::VisitMathLiteral(MathLiteral* mathlit)
{
	thestack.push(mathlit->GetValue());	
}

void EvaluateVisitor::VisitAdd(Add* add)
{
	add->GetLeft()->accept(this);
	add->GetRight()->accept(this);
	
	if (!notEvaluatable)
	{
		double temp;
		temp = thestack.top();
		thestack.pop();
		temp += thestack.top();
		thestack.pop();
		thestack.push(temp);
	}
}

void EvaluateVisitor::VisitSubtract(Subtract* sub)
{
	sub->GetLeft()->accept(this);
	sub->GetRight()->accept(this);
		
	if (!notEvaluatable)
	{
		double tempRight, tempLeft;
		tempRight = thestack.top();
		thestack.pop();
		tempLeft = thestack.top();
		thestack.pop();
		thestack.push(tempLeft - tempRight);
	}
}

void EvaluateVisitor::VisitMultiply(Multiply* multi)
{
	multi->GetLeft()->accept(this);
	multi->GetRight()->accept(this);
	
	if (!notEvaluatable)
	{
		double temp;
		temp = thestack.top();
		thestack.pop();
		temp *= thestack.top();
		thestack.pop();
		thestack.push(temp);
	}
}

void EvaluateVisitor::VisitDivide(Divide* div)
{
	div->GetLeft()->accept(this);
	div->GetRight()->accept(this);
	
	if (!notEvaluatable)
	{ //first off of stack is denominator
		double denominator;
		denominator = thestack.top();
		thestack.pop();
		
		if (denominator == 0)
			notEvaluatable = true;
		else
		{		
			double numerator = thestack.top();
			thestack.pop();
			thestack.push(numerator/denominator);
		}
	}
}

void EvaluateVisitor::VisitBoolNegate(BoolNegate* boolneg)
{
	boolneg->GetNegate()->accept(this);
	
	if (!notEvaluatable)
	{
		double temp = !(thestack.top());
		thestack.pop();
		thestack.push(temp);
	}
}

void EvaluateVisitor::VisitBoolLiteral(BoolLiteral* boollit)
{
	if (!notEvaluatable)
		thestack.push(boollit->GetValue());
}

void EvaluateVisitor::VisitBoolVariable(BoolVariable* boolvar)
{
	if (!boolvar->GetValueSet())
		notEvaluatable = true;
	else
		thestack.push(boolvar->GetValue());
}

void EvaluateVisitor::VisitBoolOr(BoolOr* orrey)
{	
	orrey->GetLeft()->accept(this);
	orrey->GetRight()->accept(this);	
	
	if (!notEvaluatable)
	{
		bool theLeft = thestack.top();
		thestack.pop();		
		bool theRight = thestack.top();
		thestack.pop();
		if (theLeft || theRight)
			thestack.push(1);
		else
			thestack.push(0);
	}
}

void EvaluateVisitor::VisitBoolAnd(BoolAnd* andes)
{
	andes->GetLeft()->accept(this);
	andes->GetRight()->accept(this);	
	
	if (!notEvaluatable)
	{
		bool theRight = thestack.top();
		thestack.pop();		
		bool theLeft = thestack.top();
		thestack.pop();
		if (theLeft && theRight)
			thestack.push(1);
		else
			thestack.push(0);
	}
}

void EvaluateVisitor::VisitGreaterThan(GreaterThan* greater)
{
	greater->GetLeft()->accept(this);
	greater->GetRight()->accept(this);
	
	if (!notEvaluatable)
	{
		double temp;
		temp = thestack.top();
		thestack.pop();
		temp = (thestack.top() > temp);
		thestack.pop();
		thestack.push(temp);
	}
}

void EvaluateVisitor::VisitLessThan(LessThan* less)
{
	less->GetLeft()->accept(this);
	less->GetRight()->accept(this);
	
	if (!notEvaluatable)
	{
		double temp;
		temp = thestack.top();
		thestack.pop();
		temp = (temp > thestack.top());
		thestack.pop();
		thestack.push(temp);
	}
}

void EvaluateVisitor::VisitEqual(Equal* eq)
{
	eq->GetLeft()->accept(this);
	eq->GetRight()->accept(this);

	if (!notEvaluatable)
	{
		double temp;
		temp = thestack.top();
		thestack.pop();
		temp = (temp == thestack.top());
		thestack.pop();
		thestack.push(temp);
	}
}

bool EvaluateVisitor::Evaluatable()
{
	return notEvaluatable;
}

double EvaluateVisitor::GetValue()
{
	if (thestack.size() < 1)
		return 0;
	else
	{
		return thestack.top();
	}	
}

void EvaluateVisitor::GetEvaluation()
{
	if (notEvaluatable)
		cout << "This expression cannot be evaluated" << endl;
	else
		cout << "Result: " << thestack.top() << endl;
}

EvaluateVisitor::EvaluateVisitor(const EvaluateVisitor& object)
{}

EvaluateVisitor& EvaluateVisitor::operator=(const EvaluateVisitor& d)
{}
