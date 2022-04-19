#include "doublylist.h"

DoublyList* createDoublyList()
{
    DoublyList  *pList;

    pList = (DoublyList *)calloc(1, sizeof(DoublyList));
    if (!pList)
        return (NULL);
    return (pList);
}

void deleteDoublyList(DoublyList* pList)
{
    clearDoublyList(pList);
    free(pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
    DoublyListNode *newNode;
    DoublyListNode *pNode;

    if (position < 0 || pList->currentElementCount < position)
    {
        printf("Wrong Approach\n");
		return (FALSE);
    }
    newNode = (DoublyListNode *)calloc(1, sizeof(DoublyListNode));
    *newNode = element;
    pNode = &pList->headerNode;
    for (int i = 0; i < position; i++)
        pNode = pNode->pRLink;
    newNode->pLLink = pNode;
    newNode->pRLink = pNode->pRLink;
    pNode->pRLink->pLLink = newNode;
    pNode->pRLink = newNode;
    pList->currentElementCount++;
    return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{
    DoublyListNode  *delNode;
    DoublyListNode  *pNode;

    if (position < 0 || pList->currentElementCount <= position)
    {
        printf("Wrong Approach\n");
        return (FALSE);
    }
    pNode = &pList->headerNode;
    for (int i = 0; i < position; i++)
        pNode = pNode->pRLink;
    delNode = pNode->pRLink;
    pNode->pRLink = delNode->pRLink;
    delNode->pRLink->pLLink = pNode;
    free(delNode);
    pList->currentElementCount--;
    return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
    int position = pList->currentElementCount - 1;
    for (;0 <= position; position--)
        removeDLElement(pList, position);
    pList->headerNode.pRLink = NULL;
}

int getDoublyListLength(DoublyList* pList)
{
    return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
    DoublyListNode  *pNode;

    if (position < 0 || pList->currentElementCount <= position)
    {
		printf("Wrong Approach\n");
		return (NULL);
	}
    pNode = &pList->headerNode;
    for (int i = 0; i <= position; i++)
        pNode = pNode->pRLink;
    return (pNode);
}

void displayDoublyList(DoublyList* pList)
{
    DoublyListNode  *pNode;

    pNode = &pList->headerNode;
    printf("Current List Length : %d\n", pList->currentElementCount);
    for (int i = 0; i < pList->currentElementCount; i++)
	{
		printf("%d",pNode->data);
		pNode = pNode->pRLink;
		if (i < pList->currentElementCount - 1)
			printf(" -> ");
	}
	printf("\n");
	return ;
}