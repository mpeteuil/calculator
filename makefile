CPLUSPLUS	= g++
CPLPLFLAGS	= `fltk-config --cxxflags` -I. -g
LDLIBS		= `fltk-config --ldflags`

APP			= calc
OBJS		= Client.cc MediatorDirector.o Widget.o CalculatorButton.o InputBox.o OutputBox.o UserInterface.o Expression.o MathExpression.o MathLiteral.o MathVariable.o MathNegate.o BinaryExpression.o Add.o Subtract.o Multiply.o Divide.o BooleanExpression.o BoolLiteral.o BoolVariable.o BoolNegate.o BoolLogical.o BoolOr.o BoolAnd.o GreaterEqualLess.o LessThan.o GreaterThan.o Equal.o Visitor.o PrintVisitor.o EvaluateVisitor.o SimplifyVisitor.o Director.o ExpressionBuilder.o LiteralBuilder.o MathLiteralBuilder.o BoolLiteralBuilder.o VariableBuilder.o MathVariableBuilder.o BoolVariableBuilder.o NegateBuilder.o MathNegateBuilder.o BoolNegateBuilder.o  BinaryExpressionBuilder.o AddBuilder.o SubtractBuilder.o MultiplyBuilder.o DivideBuilder.o GreaterThanBuilder.o LessThanBuilder.o EqualBuilder.o BoolAndBuilder.o BoolOrBuilder.o

.SUFFIXES: .cc .h .o
.cc.o:
	${CPLUSPLUS} ${CPLPLFLAGS} -c $<

${APP}:	${OBJS}
	${CPLUSPLUS} ${OBJS} ${LDLIBS} -o $@

clean::
	${RM} *.o *~ ${APP}


MediatorDirector.o: MediatorDirector.h
Widget.o: Widget.h
CalculatorButton.o: CalculatorButton.h
InputBox.o: InputBox.h
OutputBox.o: OutputBox.h
UserInterface.o: UserInterface.h
Expression.o: Expression.h
MathExpression.o: MathExpression.h Expression.h
MathLiteral.o: MathLiteral.h MathExpression.h Expression.h
MathVariable.o: MathVariable.h MathExpression.h Expression.h
MathNegate.o: MathNegate.h MathExpression.h Expression.h
BinaryExpression.o: BinaryExpression.h MathExpression.h Expression.h
Add.o: Add.h BinaryExpression.h MathExpression.h Expression.h
Subtract.o: Subtract.h BinaryExpression.h MathExpression.h Expression.h
Multiply.o: Multiply.h BinaryExpression.h MathExpression.h Expression.h
Divide.o: Divide.h BinaryExpression.h MathExpression.h Expression.h
BooleanExpression.o: BooleanExpression.h Expression.h
BoolLiteral.o: BoolLiteral.h BooleanExpression.h Expression.h
BoolVariable.o: BoolVariable.h BooleanExpression.h Expression.h
BoolNegate.o: BoolNegate.h BooleanExpression.h Expression.h
BoolLogical.o: BoolLogical.h BooleanExpression.h Expression.h
BoolOr.o: BoolOr.h BoolLogical.h BooleanExpression.h Expression.h
BoolAnd.o: BoolAnd.h BoolLogical.h BooleanExpression.h Expression.h
GreaterEqualLess.o: GreaterEqualLess.h BooleanExpression.h Expression.h
LessThan.o: LessThan.h GreaterEqualLess.h BooleanExpression.h Expression.h
GreaterThan.o: GreaterThan.h GreaterEqualLess.h BooleanExpression.h Expression.h
Equal.o: Equal.h BinaryExpression.h GreaterEqualLess.h Expression.h
Visitor.o: Visitor.h
PrintVisitor.o: PrintVisitor.h Visitor.h
EvaluateVisitor.o: EvaluateVisitor.h Visitor.h
SimplifyVisitor.o: SimplifyVisitor.h Visitor.h
Director.o: Director.h
ExpressionBuilder.o: ExpressionBuilder.h
LiteralBuilder.o: LiteralBuilder.h ExpressionBuilder.h
MathLiteralBuilder.o: MathLiteralBuilder.h LiteralBuilder.h ExpressionBuilder.h
BoolLiteralBuilder.o: BoolLiteralBuilder.h LiteralBuilder.h ExpressionBuilder.h
VariableBuilder.o: VariableBuilder.h ExpressionBuilder.h
MathVariableBuilder.o: MathVariableBuilder.h VariableBuilder.h ExpressionBuilder.h
BoolVariableBuilder.o: BoolVariableBuilder.h VariableBuilder.h ExpressionBuilder.h
NegateBuilder.o: NegateBuilder.h ExpressionBuilder.h
MathNegateBuilder.o: MathNegateBuilder.h NegateBuilder.h ExpressionBuilder.h
BoolNegateBuilder.o: BoolNegateBuilder.h NegateBuilder.h ExpressionBuilder.h
BinaryExpressionBuilder.o: BinaryExpressionBuilder.h ExpressionBuilder.h
AddBuilder.o: AddBuilder.h BinaryExpressionBuilder.h ExpressionBuilder.h
SubtractBuilder.o: SubtractBuilder.h BinaryExpression.h ExpressionBuilder.h
MultiplyBuilder.o: MultiplyBuilder.h BinaryExpression.h ExpressionBuilder.h
DivideBuilder.o: DivideBuilder.h BinaryExpression.h ExpressionBuilder.h
GreaterThanBuilder.o: GreaterThanBuilder.h BinaryExpressionBuilder.h ExpressionBuilder.h
LessThanBuilder.o: LessThanBuilder.h BinaryExpressionBuilder.h ExpressionBuilder.h
BoolAndBuilder.o: BoolAndBuilder.h BinaryExpressionBuilder.h ExpressionBuilder.h
BoolOrBuilder.o: BoolOrBuilder.h BinaryExpressionBuilder.h ExpressionBuilder.h
