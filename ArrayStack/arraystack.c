#include "arraystack.h"

ArrayStack* createArrayStack()
{
	ArrayStack	*stack;

	if (stack = (ArrayStack *)calloc(1, sizeof(ArrayStack)))
	{
		stack->pElement = (StackNode *)calloc(stack->maxElementCount, sizeof(StackNode));
		if (!stack->pElement)
			return (NULL);
	}
	else
		return (NULL);
	return (stack);
}

int pushAS(ArrayStack* pStack, StackNode element)
{
	if (isArrayStackFull(pStack))
		return (FALSE);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popAS(ArrayStack* pStack)
{
	StackNode	*popnode;

	if (isArrayStackEmpty(pStack))
		return (NULL);
	popnode = &pStack->pElement[pStack->currentElementCount];
	bzero(popnode, sizeof(StackNode));
	pStack->currentElementCount--;
	return (popnode);
}

StackNode* peekAS(ArrayStack* pStack)
{

}

void deleteArrayStack(ArrayStack* pStack)
{

}

int isArrayStackFull(ArrayStack* pStack)
{
	return (pStack->maxElementCount == pStack->currentElementCount);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	return (pStack->currentElementCount == 0);
}