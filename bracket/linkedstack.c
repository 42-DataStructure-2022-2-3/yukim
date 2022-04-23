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
	//[구조체 할당]
	//(1)
	*pNode = element;

	//(2)
	//pNode->data = element.data;
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

void printLinkedStack(LinkedStack* pStack) 
{
	StackNode	*curr;
	curr = pStack->pTopElement;
	while (curr)
	{
		if (!curr->pLink)
			break ;
		curr = curr->pLink;
		printf("%c\n", curr->data);
	}
}

int checkBracket(char *str)
{
	LinkedStack	*pStack = createLinkedStack();
	StackNode	*pNode;
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			pNode = (StackNode *)malloc(sizeof(StackNode));
			pNode->data = str[i];
			pushLS(pStack, *pNode);
			free(pNode);
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (isLinkedStackEmpty(pStack))
				return (FALSE);
			else if (str[i] - popLS(pStack)->data > 2)
				return (FALSE);
		}
		i++;
	}
	if (!isLinkedStackEmpty(pStack))
		return (FALSE);
	return (TRUE);
}