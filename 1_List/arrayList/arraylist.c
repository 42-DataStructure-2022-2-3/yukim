#include "arraylist.h"

ArrayList*	createArrayList(int maxElementCount)
{
	ArrayList *newAL;
	ArrayListNode *newALN;

	if (maxElementCount < 0)
		return (NULL);
	newAL = (ArrayList *)calloc(1, sizeof(ArrayList));
	if (!newAL)
		return (NULL);
	newALN = (ArrayListNode *)calloc(maxElementCount, sizeof(ArrayListNode));
	if (!newALN)
	{
		free(newAL);
		return (NULL);
	}
	newAL->pElement = newALN;
	newAL->maxElementCount = maxElementCount;
	return (newAL);
}

void	deleteArrayList(ArrayList* pList)
{
	if (pList)
	{
		free(pList->pElement);
		free(pList);
	}
	else
		printf("Pointer caught NULL\n");
}

int	isArrayListFull(ArrayList* pList)
{
	return (pList->currentElementCount == pList->maxElementCount);
}

int isArrayListEmpty(ArrayList* pList)
{
	return (pList->currentElementCount == 0);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	if (isArrayListFull(pList) || position < 0 || pList->currentElementCount < position)
	{
		if (isArrayListFull(pList))
			printf("Array is Full\n");
		else
			printf("Wrong Approach\n");
		return (FALSE);
	}
	for (int i = pList->currentElementCount; position < i; i--)
		pList->pElement[i] = pList->pElement[i - 1];

	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("Wrong Approach\n");
		return (FALSE);
	}
	for (int i = position; i < (pList-> currentElementCount - 1); i++)
		pList->pElement[i] = pList->pElement[i + 1];

	pList->pElement[pList->currentElementCount - 1].data = 0;
	pList->currentElementCount--;
	return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (position < 0 || pList->currentElementCount < position)
	{
		printf("Wrong Approach\n");
		return (NULL);
	}
	return (&pList->pElement[position]);
}

void displayArrayList(ArrayList* pList)
{
	if (isArrayListEmpty(pList))
		printf("ArrayList is Empty\n");
	else
	{
		for (int i = 0; i < pList->currentElementCount; i++)
			printf("ArrayList[%d] %d\n", i, pList->pElement[i].data);
	}
}

void clearArrayList(ArrayList* pList) //초기 할당 상태로 되돌려준다고 생각
{
	for(int i = 0; i < pList->currentElementCount; i++)
		pList->pElement[i].data = 0;
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList* pList)
{
	return (pList->currentElementCount);
}