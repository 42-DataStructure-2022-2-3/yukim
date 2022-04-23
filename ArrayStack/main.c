#include "arraystack.h"

int main()
{
	ArrayStack	*stack = createArrayStack(4);
	StackNode	*pnode1;
	StackNode	*pnode2;
	int i;
	printf ("is Empty? %d\n", isArrayStackEmpty(stack));
	printf ("is Full? %d\n", isArrayStackFull(stack));
	
	pnode1 = (StackNode	*)calloc(1, sizeof(StackNode));
	pnode2 = (StackNode	*)calloc(1, sizeof(StackNode));
	pnode1->data = 'A';
	pnode2->data = 'B';
	pushAS(stack, *pnode1);
	pushAS(stack, *pnode2);
	pushAS(stack, *pnode1);
	pushAS(stack, *pnode2);
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