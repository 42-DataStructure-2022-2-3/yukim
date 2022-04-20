#include "linkedlist.h"

int main(void)
{
	LinkedList	*pList;
	int			max;

	pList = createLinkedList();
	max = 5000;
	for(int i = 0; i < max; i++)
	{	
		ListNode 	pNode;
		pNode.data = i * 4 ;
		pNode.pLink = NULL;
		addLLElement(pList, i, pNode);
	}
	// ListNode ptr;
	// ptr.data = 50000;
	// ptr.pLink = NULL;
	// addLLElement(pList, 1, ptr);
	// displayLinkedList(pList);
	// printf("%d\n", getLinkedListLength(pList));
	// removeLLElement(pList, 0);
	// printf("%d\n", pList->currentElementCount);
	// printf("%d\n", getLinkedListLength(pList));
	// getLLElement(pList, 4);
	// deleteLinkedList(pList);
	timeCheck(pList, max);
	return (0);
}

void	timeCheck(LinkedList *pList, int max)
{	
	ListNode		*pNode;
	clock_t			start;
	clock_t			end;
	float			result;

	start = clock();
	pNode = getLLElement(pList, max - 1);
	end = clock();
	result = (float)(end - start) / CLOCKS_PER_SEC;
	printf("%.10f\n", result);
}