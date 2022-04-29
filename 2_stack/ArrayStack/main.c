#include "arraystack.h"

int main()
{
	ArrayStack	*stack = createArrayStack(4);
	StackNode	pNode;
	int			i;

	printf("----[createArrayStack]----\n");
	printf ("is Empty? %d\n", isArrayStackEmpty(stack));
	printf ("is Full? %d\n", isArrayStackFull(stack));
	printf("--------------------------\n");
	for(i = 0; i < 2; i++)
	{
		pNode.data = 'A' + i;
		pushAS(stack, pNode);
		printf("Pushed '%c'\n", stack->pElement[i].data);
	}
	printf ("pop : %c\n",popAS(stack)->data);
	printf ("peek : %c\n",peekAS(stack)->data);
	printf("--------------------------\n");
	printf("[Stack]\nMaxElementCount : %d\nCurrentElementCount : %d\n\n", stack->maxElementCount, stack->currentElementCount);
	i = 0;
	while (i < stack->maxElementCount)
	{
		printf("%d : %c\n", i, stack->pElement[i].data);
		i++;
	}
	deleteArrayStack(stack);
	//printf("%p\n", stack->pElement);
	
	return (0);
}