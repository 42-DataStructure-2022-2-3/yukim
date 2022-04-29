#include "linkedstack.h"

int main()
{
	LinkedStack	*stack = createLinkedStack();
	StackNode	pNode;
	int			i;

	printf("----[createLinkedStack]----\n");
	for(i = 0; i < 3; i++)
	{
		pNode.data = 'A' + i;
		pushLS(stack, pNode);
		printf("Pushed '%c'\n", stack->pTopElement->pLink->data);
	}
	printf("--------------------------\n");
	printf ("is Empty? %d\n", isLinkedStackEmpty(stack));
	printf ("is Full? %d\n", isLinkedStackFull(stack));
	printf("--------------------------\n");
	printf ("pop : %c\n",popLS(stack)->data);
	printf ("peek : %c\n",peekLS(stack)->data);
	printf("--------------------------\n");
	printf("[print stack]\n");
	printLinkedStack(stack);
	printf("\n");
	
	// deleteLinkedStack(stack);
	//printf("%p\n", stack->pTopElement);
	return 0;
}