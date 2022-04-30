#include "linkeddeque.h"

int main()
{
	LinkedDeque	*pDeque;
	DequeNode	element;

	pDeque = createLinkedDeque();
	for (int i = 0; i < 6; i++)
    {
        element.data = 'A' + i;
		if (i < 3)
        	insertFrontLD(pDeque, element);
		else
			insertRearLD(pDeque, element);
    }
	printf("isLinkedDequeFull? [%s]\n", isLinkedDequeFull(pDeque) ? "TRUE" : "FALSE");
    printf("isLinkedDequeEmpty? [%s]\n", isLinkedDequeEmpty(pDeque) ? "TRUE" : "FALSE");
	peekFrontLD(pDeque);
	peekRearLD(pDeque);
	for (int i = 0; i < 2; i++)
	{
		deleteFrontLD(pDeque);
		deleteRearLD(pDeque);
	}
	peekFrontLD(pDeque);
	peekRearLD(pDeque);
	displayLinkedDeque(pDeque);
	return (0);
}