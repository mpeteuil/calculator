/********************************************/
/*//  Director.cc                           */
/********************************************/

#include "Director.h"
#include "MathLiteralBuilder.h"
#include "MathVariableBuilder.h"
#include <string>
using namespace std;


/********************************************/
/*  Name: Create                            */
/*  Purpose: Takes a expression string and  */
/*  splits it                               */
/********************************************/

Expression* Director::Create(string originalInput)
{
	if (originalInput == "" || originalInput == "\0" || originalInput == "\n")
	{
		Expression* exp = NULL;
		return exp;
	}
	Expression* Result;
	string inputExpression = "";
	string variableValueString = "";
	bool mathFlag = false, boolFlag = false;
	
	// Gets rid of whitespace in the expression
	unsigned i = 0;
	string tempString = "";
	while (i < originalInput.size())
	{
		if (originalInput[i] != ' ')
			tempString += originalInput[i];
		i++;
	}
	originalInput = tempString;
	
	i = 0;
	bool variablesSet = false;
	while (i < originalInput.size()) // Loop til colon, then split string
	{
		if (originalInput[i] == ':')
		{
			variablesSet = true;
			i++;
		}
		if (variablesSet == false)
			inputExpression += originalInput.at(i);
		if (variablesSet == true)
			variableValueString += originalInput.at(i);
		i++;
	}
	
	
	// gets to non-whitespace characters and starts building a string, then when
	// next character is whitespace and current is not, puts current in string
	// and pushes the string into the vector.
	// Variables needed for the following while loop
	unsigned k = 0;
	string newString = "";
	string tempNewString = "";
	char* end;
	
	while (k < variableValueString.size())
	{
		while(k < variableValueString.size())
		{
			if (variableValueString.at(k) == '=')
			{
				k++;
				break;
			}
			newString += variableValueString[k];
			k++;
		}
			variables.push_back(newString);
			newString = "";
		while (k < variableValueString.size())
		{
			if (variableValueString.at(k) == ',')
			{
				k++;
				break;
			}
			newString += variableValueString[k];
			
			k++;
		}
		//convert to lowercase in order to not reject tRuE, TrUe, etc.
		for (unsigned ij = 0; ij < newString.size(); ij++)
		{
			tempNewString += tolower(newString.at(ij));
		}
		double tempDouble;
		if (tempNewString == "true")
			tempDouble = 1;
		else if (tempNewString == "false")
			tempDouble = 0;
		else
			tempDouble = strtod(newString.c_str(), &end);
		//delete end;
			
		// Push value of the variable into the variable_value vector
		variable_values.push_back(tempDouble);
		newString = "";
	}
	
	
	//ONLY FOR TESTING
	/*cout << "Variables: ";
	for (k = 0; k < variables.size(); k++)
	{
		cout << "\"" << variables[k] << "\", ";
	}
	cout << endl;
	//ONLY FOR TESTING
	
	//ONLY FOR TESTING
	cout << "Variable Values: ";
	for (k = 0; k < variable_values.size(); k++)
	{
		cout << "\"" << variable_values[k] << "\", ";
	}
	cout << endl;
	//ONLY FOR TESTING
	*/
	
	
	// Check what for which parser to call
	unsigned operandCounter = 0;
	unsigned n = 0;
	while(n < inputExpression.size())
	{
		if (inputExpression[n] == '&' || inputExpression[n] == '|' || inputExpression[n] == '=' || inputExpression[n] == '<' || inputExpression[n] == '>' || inputExpression[n] == '~')
		{
			Result = BoolParse(inputExpression);
			operandCounter++;
		}
		n++;
	}
	if (operandCounter == 0)
	{
		Result = MathParse(inputExpression);
	}
	
	variables.clear();
	variable_values.clear();
	return Result;
}


/******************************************/
//      Parser for Math expressions       //
/******************************************/

Expression* Director::MathParse(string expressionPart)
{
	unsigned parentheses = 0;
	Expression *Result;
	Expression *Left;
	Expression *Right;
	Expression *Negate;
	string leftSideString = "", rightSideString = "";
	if (expressionPart.at(0) == '(' && expressionPart.at(expressionPart.length()-1) == ')')
	{
		for (unsigned i = 0; i < expressionPart.length(); i++)
		{
			// Attempt to find middle operator...
			if (expressionPart[i] == '(')
				parentheses++;
			if (expressionPart[i] == ')')
				parentheses--;
			
			if (parentheses == 1)
			{
				//Check to see if math operator, if so, it's the middle operator
				if (expressionPart[i] == '*' || expressionPart[i] == '/' || expressionPart[i] == '+' || expressionPart[i] == '-')
				{
					for (unsigned j = 1; j < i; j++)
					{
						leftSideString += expressionPart[j];
					}
					//gets the right half from the mid operator
					for (unsigned k = i+1; k < expressionPart.length()-1; k++) 
					{
						rightSideString += expressionPart[k];
					}
					
					switch(expressionPart[i])
					{
						case '+':
						{
							AddBuilder* AD = new AddBuilder();
							Left = MathParse(leftSideString);
							Right = MathParse(rightSideString);
							Result = CreateExpression(AD, Left, Right);
							break;
						}
						case '-':
						{
							if (expressionPart.at(i-1) == '(')
							{	
								string anotherTempString = "";
								for (unsigned jn = 1; jn < expressionPart.size()-1; jn++)
								{
									anotherTempString += expressionPart.at(jn);
								}
				
								MathNegateBuilder *MathNeg = new MathNegateBuilder();
								Result = CreateNegate(MathNeg, MathParse(anotherTempString));
							}
							else
							{
								SubtractBuilder* SB = new SubtractBuilder();
								Left = MathParse(leftSideString);
								Right = MathParse(rightSideString);
								Result = CreateExpression(SB, Left, Right);
							}
							break;
						}
						case '*':
						{
							MultiplyBuilder* M = new MultiplyBuilder();
							Left = MathParse(leftSideString);
							Right = MathParse(rightSideString);
							Result = CreateExpression(M, Left, Right);
							break;
						}
						case '/':
						{
							DivideBuilder* Div = new DivideBuilder();
							Left = MathParse(leftSideString);
							Right = MathParse(rightSideString);
							Result = CreateExpression(Div, Left, Right);
							break;
						}
					}
				}
					
			}
		}
	}
	

		//Create math Literal
		else if (expressionPart.at(0) >= '0' && expressionPart.at(0) <= '9')
		{
			MathLiteralBuilder *MathLitBuild = new MathLiteralBuilder();
			//Convert to double
//			char* thing;
			double tempDouble = atof(expressionPart.c_str());
			Result = CreateLiteral(MathLitBuild, tempDouble);
		}
		else if (expressionPart.at(0) == '-')
		{
			string anotherTempString = "";
			bool operatorFlag = false, parenthesesFlag = false;
			for (unsigned j = 1; j < expressionPart.size(); j++)
			{
				if (expressionPart.at(j) == '+' || expressionPart.at(j) == '-' || expressionPart.at(j) == '*' || expressionPart.at(j) == '/' ||
					expressionPart.at(j) == '&' || expressionPart.at(j) == '|' || expressionPart.at(j) == '~' || expressionPart.at(j) == '<' ||
					expressionPart.at(j) == '>' || expressionPart.at(j) == '=')
						operatorFlag = true;
				if (expressionPart.at(j) == '(')
					parenthesesFlag = true;
				anotherTempString += expressionPart.at(j);
			}
			if (!operatorFlag)
			{
				if (parenthesesFlag)
				{
					string tempString = "";
					tempString = (anotherTempString.substr(1, anotherTempString.size()-2));
					anotherTempString = tempString;
				}
				
			}
			MathNegateBuilder *MathNeg = new MathNegateBuilder();
			Result = CreateNegate(MathNeg, MathParse(anotherTempString));
		}
		else if	(expressionPart.at(0) != '(') //Problematic for Negate, becasue there will be a - in this position
		{
			//Build math variable
			MathVariableBuilder *MathVarBuild = new MathVariableBuilder();
			Result = CreateVariable(MathVarBuild, expressionPart);
		}
	
	return Result;
}


/******************************************/
//     Parser for boolean expressions     //
/******************************************/
Expression* Director::BoolParse(string expressionPart)
{
	unsigned parentheses = 0;
	Expression *Result;
	Expression *Left;
	Expression *Right;
	Expression *temp;
	string leftSideString = "", rightSideString = "";

	
	for (unsigned i = 0; i < expressionPart.length(); i++)
	{
		
		// Attempt to find middle operator...
		if (expressionPart[i] == '(')
			parentheses++;
		if (expressionPart[i] == ')')
			parentheses--;
		
		if (parentheses == 1)
		{
			//Check to see if math operator, if so, it's the middle operator
			if (expressionPart[i] == '*' || expressionPart[i] == '/' || expressionPart[i] == '+' || expressionPart[i] == '-' || expressionPart[i] == '|' || expressionPart[i] == '&' || expressionPart[i] == '<' || expressionPart[i] == '>' || expressionPart[i] == '=')
			{
				for (unsigned j = 1; j < i; j++)
				{
					leftSideString += expressionPart[j];
				}
				//gets the right half from the mid operator
				for (unsigned k = i+1; k < expressionPart.length()-1; k++) 
				{
					rightSideString += expressionPart[k];
				}
				
				switch(expressionPart[i])
				{
					case '+':
					{
						AddBuilder* AD = new AddBuilder();
						Left = BoolParse(leftSideString);
						Right = BoolParse(rightSideString);
						Result = CreateExpression(AD, Left, Right);
						break;
					}
					case '-':
					{
						SubtractBuilder* SB = new SubtractBuilder();
						Left = BoolParse(leftSideString);
						Right = BoolParse(rightSideString);
						Result = CreateExpression(SB, Left, Right);
						break;
					}
					case '*':
					{
						MultiplyBuilder* M = new MultiplyBuilder();
						Left = BoolParse(leftSideString);
						Right = BoolParse(rightSideString);
						Result = CreateExpression(M, Left, Right);
						break;
					}
					case '/':
					{
						DivideBuilder* Div = new DivideBuilder();
						Left = BoolParse(leftSideString);
						Right = BoolParse(rightSideString);
						Result = CreateExpression(Div, Left, Right);
						break;
					}
					case '|':
					{
						BoolOrBuilder *Or = new BoolOrBuilder();
						Left = BoolParse(leftSideString);
						Right = BoolParse(rightSideString);
						Result = CreateExpression(Or, Left, Right);
						break;
					}
					case '&':
					{
						BoolAndBuilder *And = new BoolAndBuilder();
						Left = BoolParse(leftSideString);
						Right = BoolParse(rightSideString);
						Result = CreateExpression(And, Left, Right);
						break;
					}
					case '<':
					{
						LessThanBuilder *Less = new LessThanBuilder();
						Left = MathParse(leftSideString);
						Right = MathParse(rightSideString);
						Result = CreateExpression(Less, Left, Right);
						break;
					}
					case '>':
					{
						GreaterThanBuilder *Greater = new GreaterThanBuilder();
						Left = MathParse(leftSideString);
						Right = MathParse(rightSideString);
						Result = CreateExpression(Greater, Left, Right);
						break;
					}
					case '=':
					{
						EqualBuilder *Equal = new EqualBuilder();
						Left = MathParse(leftSideString);
						Right = MathParse(rightSideString);
						Result = CreateExpression(Equal, Left, Right);
						break;
					}
				}
			}
				
		}
	}

		//Create math Literal
		if (expressionPart.at(0) >= '0' && expressionPart.at(0) <= '9')
		{
			BoolLiteralBuilder *BoolLitBuild = new BoolLiteralBuilder();
			//Convert to double
//			char* thing;
			double tempDouble = atof(expressionPart.c_str());
			Result = CreateLiteral(BoolLitBuild, tempDouble);
		}
		else if (expressionPart.at(0) == '~')
		{
			// Re-Create the left side
			leftSideString = "";
			bool operatorFlag = false, parenthesesFlag = false;
			for (unsigned j = 1; j < expressionPart.size(); j++)
			{
				if (expressionPart.at(j) == '+' || expressionPart.at(j) == '-' || expressionPart.at(j) == '*' || expressionPart.at(j) == '/' ||
					expressionPart.at(j) == '&' || expressionPart.at(j) == '|' || expressionPart.at(j) == '~' || expressionPart.at(j) == '<' ||
					expressionPart.at(j) == '>' || expressionPart.at(j) == '=')
						operatorFlag = true;
				if (expressionPart.at(j) == '(')
					parenthesesFlag = true;
				leftSideString += expressionPart.at(j);
			}		
			if (!operatorFlag)
			{
				if (parenthesesFlag)
				{
					string tempString = "";
					tempString = (leftSideString.substr(1, leftSideString.size()-2));
					leftSideString = tempString;
				}
				
			}
			BoolNegateBuilder *BoolNeg = new BoolNegateBuilder();
			//Left = BoolParse(leftSideString); //ONLY LEFT?
			Result = CreateNegate(BoolNeg, BoolParse(leftSideString));
		}
		/*if (expressionPart.at(0) == '~')
		{
			string tempExpressionPart = "";
			for (unsigned jk = 1; jk < expressionPart.size(); jk++)
			{ 
				tempExpressionPart += expressionPart.at(jk);
			}
			Expression* nully = NULL;
			temp = BoolParse(tempExpressionPart);
			BoolNegateBuilder *BNB = new BoolNegateBuilder();
			return CreateExpression(BNB, temp, nully);
		}*/
		else if (expressionPart == "true" || expressionPart == "TRUE") // Should check for TrUe or tRuE etc, use tolower()
		{
			BoolLiteralBuilder *BoolLitBuild = new BoolLiteralBuilder();
			Result = CreateLiteral(BoolLitBuild, 1);
		}
		else if (expressionPart == "false" || expressionPart == "FALSE")
		{
			BoolLiteralBuilder *BoolLitBuild = new BoolLiteralBuilder();
			Result = CreateLiteral(BoolLitBuild, 0);
		}
		else if	(expressionPart.at(0) != '(') //Problematic for Negate, because there will be a - in this position
		{
			//Build math variable
			BoolVariableBuilder *BoolVarBuild = new BoolVariableBuilder();
			Result = CreateVariable(BoolVarBuild, expressionPart);
		}
		
	return Result;
}

Expression* Director::CreateLiteral(LiteralBuilder* builderMan, double dub)
{
	builderMan->BuildLiteral(dub);
	Expression* temp = builderMan->GetExpression();
	delete builderMan; 
	return temp;
}

Expression* Director::CreateVariable(VariableBuilder* builderMan, string V)
{
	unsigned i = 0;
	bool B;
	double D;
	// Go through vector of variables and check if variables have values
	//cout << "variable vector size: " << variables.size() << endl;
	while(i < variables.size())
	{
		//cout << "curr_var: " << variables.at(i) << endl;
		if (variables.at(i) == V)
		{
			//cout << "Variable: " << V << endl;
				B = true;
				builderMan->BuildVariableBool(B);
				builderMan->BuildVariableValue(variable_values.at(i));
				builderMan->BuildVariableName(V);
				Expression* temp = builderMan->GetExpression();
				delete builderMan;
				return temp;
		}
		i++;
	}
		B = false;
		builderMan->BuildVariableBool(B);
		builderMan->BuildVariableName(V);
		
		Expression* temp = builderMan->GetExpression();
		delete builderMan;
		return temp;
}

Expression* Director::CreateNegate(NegateBuilder* builderMan, Expression* negation)
{
	builderMan->BuildNegate(negation);
	Expression* temp = builderMan->GetExpression();
	delete builderMan;
	return temp;
}

Expression* Director::CreateExpression(BinaryExpressionBuilder* builderMan, Expression* L, Expression* R)
{
	builderMan->BuildLeft(L);
	builderMan->BuildRight(R);
	return builderMan->GetExpression();
}

Director::Director()
{
}

Director::~Director()
{
}

Director::Director(const Director& object)
{
}

Director& Director::operator=(const Director& d)
{
}
