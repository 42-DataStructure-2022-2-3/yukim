#include "circularList.h"

CircularList* createCircularList()
{
	CircularList	*pList;
	
	pList = (CircularList *)calloc(1, sizeof(CircularList));
	return(pList);
}

int addCLElement(CircularList* pList, int position, CListNode element)
{
	CListNode	*curr;
	CListNode	*addNode;
	int			i;

	if (position < 0 || pList->currentElementCount < position)
	{
		printf("Wrong Approach\n");
		return (FALSE);
	}
	if (position == 0)
		return (addFirstElement(pList, position, element));
	addNode = (CListNode *)calloc(1, sizeof(CListNode));
	*addNode = element; 
	curr = &pList->headerNode;
	for (int i = 0; i < position; i++)
		curr = curr->pLink;
	addNode->pLink = curr->pLink;
	curr->pLink = addNode;
	pList->currentElementCount++;
	return (TRUE);
}

int addFirstElement(CircularList* pList, int position, CListNode element)
{
	CListNode	*lastNode;
	CListNode	*addNode;

	addNode = (CListNode *)calloc(1, sizeof(CListNode));
	*addNode = element; 
	lastNode = &pList->headerNode;
	for (int i = 0; i < pList->currentElementCount; i++)
		lastNode = lastNode->pLink;
	if (pList->currentElementCount == 0)
	{
		pList->headerNode.pLink = addNode;
		addNode->pLink = addNode;
	}
	else
	{
		addNode->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = addNode;
		lastNode->pLink = addNode;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeCLElement(CircularList* pList, int position)
{
	CListNode	*curr;
	CListNode	*delNode;

	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("Wrong Approach\n");
		return (FALSE);
	}
	if (position == 0)
		return(removeFirstElement(pList, position));
	curr = &pList->headerNode;
	for (int i = 0; i < position; i++)
		curr = curr->pLink;
	delNode = curr->pLink;
	curr->pLink = delNode->pLink;
	free(delNode);
	pList->currentElementCount--;
	return (TRUE);
}

int removeFirstElement(CircularList* pList, int position)
{
	CListNode	*curr;
	CListNode	*delNode;

	curr = pList->headerNode.pLink;
	if (position == pList->currentElementCount - 1)
	{	
		free(pList->headerNode.pLink);
		pList->headerNode.pLink = NULL;
	}
	else
	{
		delNode = pList->headerNode.pLink;
		for(int i = 0; i < pList->currentElementCount; i++)
			curr = curr->pLink;
		curr->pLink = delNode->pLink;
		pList->headerNode.pLink = delNode->pLink;
		free(delNode);
	}
	pList->currentElementCount--;
	return (TRUE);
}

CListNode* getCLElement(CircularList* pList, int position)
{
	CListNode	*curr;

	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("Wrong Approach\n");
		return (NULL);
	}
	curr = &pList->headerNode;
	for (int i = 0; i <= position; i++)
		curr = curr->pLink;
	return (curr);
}

void clearCircularList(CircularList* pList)
{
	int position = pList->currentElementCount - 1;
	for (; 0 <= position; position--)
		removeCLElement(pList, position);
}

int getCircularListLength(CircularList* pList)
{
	return (pList->currentElementCount);
}

void deleteCircularList(CircularList* pList)
{
	clearCircularList(pList);
	free(pList);
}

void displayCircularList(CircularList *pList)
{
	CListNode	*pNode;

	pNode = (CListNode *)calloc(1, sizeof(CListNode));
	pNode = pList->headerNode.pLink;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		printf("%d",pNode->data);
		pNode = pNode->pLink;
		if (i < pList->currentElementCount - 1)
			printf("->");
	}
	printf("\n");
	return ;
}