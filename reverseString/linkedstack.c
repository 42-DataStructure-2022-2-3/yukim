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

char* printReverseStringLinkedStack(LinkedStack* pStack) 
{
	char *rev_str = (char *)malloc(sizeof(char) * pStack->currentElementCount);

	StackNode	*curr;
	int			i;

	i = 0;
	curr = pStack->pTopElement;
	while (curr)
	{
		if (!curr->pLink)
			break ;
		curr = curr->pLink;
		rev_str[i] = curr->data;
		i++;
	}
	rev_str[i] = '\0';
	printf("rev_str : %s\n", rev_str);
	return (rev_str);
}