/********************************************/
/*//  Director.h                            */
/********************************************/

#ifndef DIRECTOR_
#define DIRECTOR_

#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "MathNegateBuilder.h"
#include "MathLiteralBuilder.h"
#include "MathVariableBuilder.h"
#include "AddBuilder.h"
#include "SubtractBuilder.h"
#include "MultiplyBuilder.h"
#include "DivideBuilder.h"
#include "BoolNegateBuilder.h"
#include "BoolLiteralBuilder.h"
#include "BoolVariableBuilder.h"
#include "BoolOrBuilder.h"
#include "BoolAndBuilder.h"
#include "GreaterThanBuilder.h"
#include "LessThanBuilder.h"
#include "EqualBuilder.h"


class MathNegateBuilder;
class MathLiteralBuilder;
class MathVariableBuilder;
class AddBuilder;
class SubtractBuilder;
class MultiplyBuilder;
class DivideBuilder;
class BoolNegateBuilder;
class BoolLiteralBuilder;
class BoolVariableBuilder;
class BoolOrBuilder;
class BoolAndBuilder;
class GreaterThanBuilder;
class LessThanBuilder;
class EqualBuilder;

class Director
{
public:
	Director();
	~Director();
	Expression* Create(string);
	Expression* MathParse(string);
	Expression* BoolParse(string);
	Expression* CreateLiteral(LiteralBuilder*, double);
	Expression* CreateVariable(VariableBuilder*, string);
	Expression* CreateNegate(NegateBuilder*, Expression*);
	Expression* CreateExpression(BinaryExpressionBuilder*, Expression*, Expression*);
    
private:
	//string inputExpression;
	vector<string> variables;
	vector<double> variable_values;
  	Director(const Director& object);
	Director& operator=(const Director& d);
};

#endif
