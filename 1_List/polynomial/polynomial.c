#include "polynomial.h"

LinkedList* createLinkedList()
{
	LinkedList	*pList;
	
	pList = (LinkedList *)calloc(1, sizeof(LinkedList));
	if (!pList)
		return (NULL);
	return(pList);
}

ListNode* createNode(int coef, int degree)
{
    ListNode    *newNode;

    newNode = (ListNode *)calloc(1, sizeof(ListNode));
    if (!newNode)
        return (NULL);
    newNode->coef = coef;
    newNode->degree= degree;
    return (newNode);
}

int addLLElement(LinkedList* pList, int position, ListNode *element)
{
	ListNode	*pNode;

	if (position < 0 || pList->currentElementCount < position)
	{
		printf("Wrong Approach\n");
		return (FALSE);
	}
	pNode = &pList->headerNode;
	for (int i = 0; i < position; i++)
		pNode = pNode->pLink;
	element->pLink = pNode->pLink;
	pNode->pLink = element;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*pNode;
	ListNode	*delNode;

	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("Wrong Approach\n");
		return (FALSE);
	}
	pNode = &pList->headerNode;
	for (int i = 0; i < position; i++)
		pNode = pNode->pLink;
	delNode = pNode->pLink;
	pNode->pLink = delNode->pLink;
	free(delNode);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*pNode;

	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("Wrong Approach\n");
		return (NULL);
	}
	pNode = &pList->headerNode;
	for (int i = 0; i <= position; i++)
		pNode = pNode->pLink;
	return (pNode);
}

void clearLinkedList(LinkedList* pList)
{
	int position = pList->currentElementCount - 1;
	for (; 0 <= position; position--)
		removeLLElement(pList, position);
	pList->headerNode.pLink = NULL;
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free(pList);
}

void displayLinkedList(LinkedList *pList)
{
	ListNode	*pNode;

	pNode = pList->headerNode.pLink;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		printf("%d", pNode->coef);
		if (pNode->degree != 0)
			printf("x^%d", pNode->degree);
		pNode = pNode->pLink;
		if (i < pList->currentElementCount - 1)
			printf(" + ");
	}
	printf("\n");
	return ;
}

LinkedList*	addPolyNode(LinkedList *a, LinkedList *b)
{
	LinkedList	*ret;
	ListNode 	*aNode;
	ListNode	*bNode;
	int			i;

	ret = createLinkedList();
	aNode = a->headerNode.pLink;
	bNode = b->headerNode.pLink;
	i = 0;
	while (aNode && bNode)
	{
		ListNode	*newNode;
		if (aNode->degree == bNode->degree)
		{
			newNode = createNode(aNode->coef + bNode->coef, aNode->degree);
			aNode = aNode->pLink;
			bNode = bNode->pLink;
		}
		else if (aNode->degree > bNode->degree)
		{
			newNode = createNode(aNode->coef, aNode->degree);
			aNode = aNode->pLink;
		}
		else if (aNode->degree < bNode->degree)
		{
			newNode = createNode(bNode->coef, bNode->degree);
			bNode = bNode->pLink;
		}
		addLLElement(ret, i, newNode);
		i++;
	}
	if (aNode == NULL)
	{
		while (bNode)
		{
			ListNode	*newNode;
			newNode = createNode(bNode->coef, bNode->degree);
			addLLElement(ret, i, newNode);
			bNode = bNode->pLink;
			i++;
		}
	}
	else if (bNode == NULL)
	{
		while (aNode)
		{
			ListNode	*newNode;
			newNode = createNode(aNode->coef, aNode->degree);
			addLLElement(ret, i, newNode);
			aNode = aNode->pLink;
			i++;
		}
	}
	return (ret);
}