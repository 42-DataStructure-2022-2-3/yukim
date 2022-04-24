#include "linkedstack.h"

int main()
{
	LinkedStack	*stack = createLinkedStack();
	
	// ABCDE
	StackNode	*pNode;
	int			i;
	for(i = 0; i < 5; i++)
	{
		pNode = (StackNode	*)calloc(1, sizeof(StackNode));
		pNode->data = 'A' + i;
		pushLS(stack, *pNode);
	}

	printLinkedStack(stack);
	printReverseStringLinkedStack(stack);

	printf("!\n");
	
	return 0;
}








	// printf ("is Empty? %d\n", isLinkedStackEmpty(stack));
	// printf ("is Full? %d\n", isLinkedStackFull(stack));
	// printf ("pop : %c\n",popLS(stack)->data);
	// printf ("peek : %c\n",peekLS(stack)->data);
	// deleteLinkedStack(stack);
	//printf("%p\n", stack->pTopElement);