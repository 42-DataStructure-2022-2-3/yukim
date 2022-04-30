#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque	*pDeque;

	pDeque = (LinkedDeque *)calloc(1, sizeof(DequeNode));
	return (pDeque);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*insertNode;

	insertNode = (DequeNode *)calloc(1, sizeof(DequeNode));
	insertNode->data = element.data;
	if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = insertNode;
		pDeque->pRearNode = insertNode;
	}
	else
	{
		pDeque->pFrontNode->pLLink = insertNode;
		insertNode->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode = insertNode;
	}
	pDeque->currentElementCount++;
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*insertNode;

	insertNode = (DequeNode *)calloc(1, sizeof(DequeNode));
	insertNode->data = element.data;
	if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = insertNode;
		pDeque->pRearNode = insertNode;
	}
	else
	{
		pDeque->pRearNode->pRLink = insertNode;
		insertNode->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = insertNode;
	}
	pDeque->currentElementCount++;
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode	*retNode;

	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	retNode = pDeque->pFrontNode;
	if (pDeque->currentElementCount > 1)
	{	
		pDeque->pFrontNode = retNode->pRLink;
		pDeque->pFrontNode->pLLink = NULL;
		retNode->pRLink = NULL;
	}
	else
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	pDeque->currentElementCount--;
	return (retNode);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode	*retNode;

	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	retNode = pDeque->pRearNode;
	if (pDeque->currentElementCount > 1)
	{	
		pDeque->pRearNode = retNode->pLLink;
		pDeque->pRearNode->pRLink = NULL;
		retNode->pLLink = NULL;
	}
	else
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	pDeque->currentElementCount--;
	return (retNode);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode	*tmp;

	if (!isLinkedDequeEmpty(pDeque))
	{
		while (pDeque->currentElementCount > 0)
		{
			if (pDeque->currentElementCount > 1)
			{
				tmp = deleteRearLD(pDeque);
				free(tmp);
			}
			tmp = deleteFrontLD(pDeque);
			free(tmp);
		}
	}
	free(pDeque);
	memset(pDeque, 0, sizeof(LinkedDeque));
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
	return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	return (pDeque->currentElementCount == 0);
}