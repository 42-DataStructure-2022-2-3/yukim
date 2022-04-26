#include "linkedstack.h"

int main()
{
	ExprToken	*exp;
	ExprToken	*postfix;
	int cnt;

	// (5 + 1) * 2
	
	exp = (ExprToken *)calloc(7, sizeof(ExprToken)); 

	exp[0].type = lparen;
	exp[0].value = 0;

	exp[1].type = operand;
	exp[1].value = 5;
	exp[2].type = plus;
	exp[2].value = 0;
	exp[3].type = operand;
	exp[3].value = 1;

	exp[4].type = rparen;
	exp[4].value = 0;

	exp[5].type = times;
	exp[5].value = 0;
	exp[6].type = operand;
	exp[6].value = 2;

	postfix = infixToPostfix(exp, 7);
	
	printf("%d\n", computePostfix(postfix, getPostfixLength(exp, 7)));

	// (A - (B + C)) * D
	
	// exp = (ExprToken *)calloc(11, sizeof(ExprToken));
	// exp[0].type = lparen;
	// exp[0].value = 0;
	
	// exp[1].type = operand;
	// exp[1].value = 'A';
	// exp[2].type = minus;
	// exp[2].value = 0;

	// exp[3].type = lparen;
	// exp[3].value = 0;
	// exp[4].type = operand;
	// exp[4].value = 'B';
	// exp[5].type = plus;
	// exp[5].value = 0;
	// exp[6].type = operand;
	// exp[6].value = 'C';
	// exp[7].type = rparen;
	// exp[7].value = 0;
	// exp[8].type = rparen;
	// exp[8].value = 0;

	// exp[9].type = times;
	// exp[9].value = 0;
	// exp[10].type = operand;
	// exp[10].value = 'D';

	// postfix = infixToPostfix(exp, 11);
	// printf("%d\n", computePostfix(postfix, getPostfixLength(exp, 11)));
	
	return 0;
}