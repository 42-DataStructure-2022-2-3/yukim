#include "linkedstack.h"

int main()
{
	LinkedStack	*stack = createLinkedStack();
	StackNode	*pNode;
	int			i;

	for(i = 0; i < 2; i++)
	{
		pNode = (StackNode	*)calloc(1, sizeof(StackNode));
		pNode->data = 'A' + i;
		pushLS(stack, *pNode);
	}
	printf ("is Empty? %d\n", isLinkedStackEmpty(stack));
	printf ("is Full? %d\n", isLinkedStackFull(stack));
	printf ("pop : %c\n",popLS(stack)->data);
	printf ("peek : %c\n",peekLS(stack)->data);

	printLinkedStack(stack);
	printf("!\n");
	
	// deleteLinkedStack(stack);
	//printf("%p\n", stack->pTopElement);
	return 0;
}