#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack	*stack;
	StackNode	*DummyNode;

	stack = (LinkedStack *)calloc(1, sizeof(LinkedStack));
	if (!stack)
		return (NULL);
	DummyNode = (StackNode *)calloc(1, sizeof(StackNode));
	stack->pTopElement = DummyNode;
	return (stack);	
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode	*pNode;

	pNode = (StackNode *)calloc(1, sizeof(StackNode));
	if (!pNode)
		return (FALSE);
	pNode->data = element.data;
	if (pStack->currentElementCount == 0)
		pStack->pTopElement->pLink = pNode;
	else
	{
	if (pStack->currentElementCount != 0)
		pNode->pLink = pStack->pTopElement->pLink; 
		pStack->pTopElement->pLink = pNode;
	}
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode	*popNode;

	if (isLinkedStackEmpty(pStack))
		return (NULL);

	popNode = pStack->pTopElement->pLink;
	pStack->pTopElement->pLink = popNode->pLink;
	popNode->pLink = NULL;
	pStack->currentElementCount--;
	return (popNode);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	return (pStack->pTopElement->pLink);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode	*curr;

	curr = pStack->pTopElement->pLink;
	while (curr)
	{
		free(curr);
		curr = curr->pLink;
	}
	bzero(pStack, sizeof(LinkedStack));
	free(pStack);
}

int isLinkedStackFull(LinkedStack* pStack)
{
	return (FALSE);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	return (pStack->currentElementCount == 0);
}

void printPostfix(ExprToken	*postfix, int len) 
{
	for (int i = 0; i < len ; i++)
	{
		if (postfix[i].type == times)
			printf("* ");
		else if (postfix[i].type == divide)
			printf("/ ");
		else if (postfix[i].type == plus)
			printf("+ ");
		else if (postfix[i].type == minus)
			printf("- ");
		else
			printf("%d ", postfix[i].value);
	}
	printf("\n");
}

int getPostfixLength(ExprToken* infix, int size)
{
	int cnt = 0;

	for (int i = 0; i < size; i++) // infix[i].type == 0
	{
		if (infix[i].type != lparen && infix[i].type != rparen)
			cnt++;
	}
	return (cnt);
}

ExprToken* infixToPostfix(ExprToken* infix, int size) // 중위표기 를 후위표기 로 변환
{
	ExprToken	*postfix;
	LinkedStack	*opStack;
	StackNode	element;
	StackNode	*popNode;
	int			len;
	int			j;

	opStack = createLinkedStack();
	len = getPostfixLength(infix, size);
	postfix = (ExprToken *)calloc(len, sizeof(ExprToken));
	j = 0;
	for (int i = 0; i < size; i++)
	{
		if (infix[i].type == operand)
		{
			postfix[j].type = infix[i].type;
			postfix[j].value = infix[i].value;
			j++;
		}
		else if (infix[i].type == rparen)
		{	
			while (opStack->pTopElement->pLink->data.type)
			{
				popNode = popLS(opStack);
				if (popNode->data.type == lparen)
				{
					free(popNode);
					break ;
				}
				postfix[j].type = popNode->data.type;
				postfix[j].value = popNode->data.value;
				free(popNode);
				j++;
			}
		}
		else
		{
			element.data.type = infix[i].type;
			element.data.value = infix[i].value;
			pushLS(opStack, element);
		}
	}
	while (opStack->pTopElement->pLink)
	{
		popNode = popLS(opStack);
		postfix[j].type = popNode->data.type;
		postfix[j].value = popNode->data.value;
		free(popNode);
		j++;
	}
	printPostfix(postfix, len);
	return (postfix);
}

StackNode	*calculator(int a, int b, Precenence type)
{
	StackNode *pNode = (StackNode *)calloc(1, sizeof(StackNode));
	if(pNode == NULL)
		return NULL;
	pNode->data.type = operand;
	if (type == plus) 
	{
		pNode->data.value = a + b;
	}
	if (type == minus) 
	{
		pNode->data.value = a - b;
	}
	if (type == times) 
	{
		pNode->data.value = a * b;
	}
	if (type == divide) 
	{
		pNode->data.value = a / b;
	}

	return pNode;
}

int computePostfix(ExprToken* postfix, int size) // 후위표기 를 계산 -> int
{
	LinkedStack	*outStack;
	StackNode	element;
	StackNode	*op1, *op2, *res;

	outStack = createLinkedStack();
	for (int i = 0; i < size; i++)
	{
		if (postfix[i].type == operand)
		{
			element.data.type = postfix[i].type;
			element.data.value = postfix[i].value;
			pushLS(outStack, element);
		}
		else
		{
			op1 = popLS(outStack);
			op2 = popLS(outStack);
			int a = op1->data.value;
			int b = op2->data.value;
			free(op1); free(op2);
			pushLS(outStack, *calculator(a, b, postfix[i].type));
		}
	}
	res = popLS(outStack);
	return (res->data.value);
}