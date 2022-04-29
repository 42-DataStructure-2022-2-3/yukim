#ifndef _LINKED_STACK_
#define _LINKED_STACK_

# include <stdio.h>
# include <stdlib.h>
# include <string.h> 

typedef enum PrecedenceType 
{
	lparen = 1, rparen, times, divide, plus, minus, operand
} Precenence;

typedef struct ExprTokenType
{
	int	value;
	Precenence type;
} ExprToken;

typedef struct StackNodeType
{
	struct ExprTokenType data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// ���� ������ ����
	StackNode* pTopElement;		// Top ����� ������
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

void printPostfix(ExprToken	*postfix, int len);
int getPostfixLength(ExprToken* infix, int size);
ExprToken* infixToPostfix(ExprToken* infix, int size);
int computePostfix(ExprToken* postfix, int size);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif