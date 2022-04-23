#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack	*stack;

	if (stack = (LinkedStack *)calloc(1, sizeof(LinkedStack)))
		return (stack);
	return (NULL);	
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode	*pNode;

	if (pNode = (StackNode *)calloc(1, sizeof(StackNode)))
	{
		*pNode = element;
		pNode->pLink = pStack->pTopElement; 
		pStack->pTopElement->pLink = pNode;
		return (TRUE);
	}
	return (FALSE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode	*popNode;

	popNode = pStack->pTopElement;
	pStack->pTopElement->pLink = 
}

StackNode* peekLS(LinkedStack* pStack)
{

}

void deleteLinkedStack(LinkedStack* pStack)
{

}

int isLinkedStackFull(LinkedStack* pStack)
{
	return (FALSE);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	return (pStack->currentElementCount == 0);
}