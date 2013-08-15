/********************************************/
/*//  PrintVisitor.cc                       */
/********************************************/

#include "PrintVisitor.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//PrintVisitor::PrintVisitor()
//{}

PrintVisitor::~PrintVisitor()
{}

void PrintVisitor::VisitMathNegate(MathNegate* mathneg)
{
	value_ += "-";
	mathneg->GetNegate()->accept(this);
	///cout << "";
}

void PrintVisitor::VisitMathVariable(MathVariable* mathvar)
{
	value_ += mathvar->GetName();
}

void PrintVisitor::VisitMathLiteral(MathLiteral* mathlit)
{
	double val = mathlit->GetValue();
	string s;
	stringstream s2;
	s2 << val;
	s = s2.str();
	value_ += s;
}

void PrintVisitor::VisitAdd(Add* addy)
{
	value_ += "(";
	addy->GetLeft()->accept(this);
	value_ += "+";
	addy->GetRight()->accept(this);
	value_ += ")";
}

void PrintVisitor::VisitSubtract(Subtract* sub)
{
	value_ += "(";
	sub->GetLeft()->accept(this);
	value_ += "-";
	sub->GetRight()->accept(this);
	value_ += ")";
}

void PrintVisitor::VisitMultiply(Multiply* multi)
{
	value_ += "(";
	multi->GetLeft()->accept(this);
	value_ += "*";
	multi->GetRight()->accept(this);
	value_ += ")";
}

void PrintVisitor::VisitDivide(Divide* div)
{
	value_ += "(";
	div->GetLeft()->accept(this);
	value_ += "/";
	div->GetRight()->accept(this);
	value_ += ")";
}

void PrintVisitor::VisitBoolNegate(BoolNegate* boolneg)
{	
	value_ += "~";
	boolneg->GetNegate()->accept(this);
	//cout << '';
	
}

void PrintVisitor::VisitBoolLiteral(BoolLiteral* boollit)
{
	bool B = boollit->GetValue();
	if (B)
	value_ += "TRUE";
	else
	value_ += "FALSE";
}

void PrintVisitor::VisitBoolVariable(BoolVariable* boolvar)
{
	value_ += boolvar->GetName();
}

void PrintVisitor::VisitBoolOr(BoolOr* boolor)
{
	value_ += "(";
	boolor->GetLeft()->accept(this);
	value_ += "|";
	boolor->GetRight()->accept(this);
	value_ += ")";
}

void PrintVisitor::VisitBoolAnd(BoolAnd* booland)
{
	value_ += "(";
	booland->GetLeft()->accept(this);
	value_ += "&";
	booland->GetRight()->accept(this);
	value_ += ")";
}

void PrintVisitor::VisitGreaterThan(GreaterThan* greater)
{
	value_ += "(";
	greater->GetLeft()->accept(this);
	value_ += ">";
	greater->GetRight()->accept(this);
	value_ += ")";
}

void PrintVisitor::VisitLessThan(LessThan* less)
{
	value_ += "(";
	less->GetLeft()->accept(this);
	value_ += "<";
	less->GetRight()->accept(this);
	value_ += ")";
}

void PrintVisitor::VisitEqual(Equal* eq)
{
	value_ += "(";
	eq->GetLeft()->accept(this);
	value_ += "=";
	eq->GetRight()->accept(this);
	value_ += ")";
}

string PrintVisitor::GetPrint()
{
	string tempString = "";
	tempString = value_;
	value_ = "";
	return tempString;
}

PrintVisitor::PrintVisitor(const PrintVisitor& object)
{}

PrintVisitor& PrintVisitor::operator=(const PrintVisitor& d)
{}
