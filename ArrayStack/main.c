#include "arraystack.h"

int main()
{
	ArrayStack	*stack = createArrayStack(4);
	StackNode	*pNode;
	int i;
	printf ("is Empty? %d\n", isArrayStackEmpty(stack));
	printf ("is Full? %d\n", isArrayStackFull(stack));
	
	for(i = 0; i < 2; i++)
	{
		pNode = (StackNode	*)calloc(1, sizeof(StackNode));
		pNode->data = 'A' + i;
		pushAS(stack, *pNode);
	}
	printf ("pop : %c\n",popAS(stack)->data);
	printf ("peek : %c\n",peekAS(stack)->data);
	
	printf("!\n");
	i = 0;
	while (i < stack->maxElementCount)
	{
		printf("%d : %c\n", i, stack->pElement[i].data);
		i++;
	}
	deleteArrayStack(stack);
	printf("%p\n", stack->pElement);
	
	return (0);
}