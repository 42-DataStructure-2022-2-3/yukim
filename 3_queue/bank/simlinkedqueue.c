#include "simlinkedqueue.h"

Linkedqueue* createLinkedQueue()
{
	Linkedqueue	*pQueue;

	pQueue = (Linkedqueue *)calloc(1, sizeof(Linkedqueue));
	return (pQueue);
}

int enqueueLQ(Linkedqueue* pQueue, queueNode element)
{
	queueNode	*curr;
	queueNode	*insertNode;

	insertNode = (queueNode	*)calloc(1, sizeof(queueNode));
	insertNode->data = element.data;
	curr = pQueue->pFrontNode;
	if (!curr)
	{
		pQueue->pFrontNode = insertNode;
		pQueue->pRearNode = insertNode;
	}
	else
	{
		pQueue->pRearNode->pLink = insertNode;
		pQueue->pRearNode = insertNode;
	}
	pQueue->currentElementCount++;
	return (TRUE);
}

queueNode* dequeueLQ(Linkedqueue* pQueue)
{
	queueNode	*retNode;

	if (isLinkedQueueEmpty(pQueue))
		return (NULL);
	retNode = pQueue->pFrontNode;
	if (pQueue->currentElementCount > 1)
	{
		pQueue->pFrontNode = pQueue->pFrontNode->pLink;
		retNode->pLink = NULL;
	}
	else
	{
		pQueue->pFrontNode = NULL;
		pQueue->pRearNode = NULL;
	}
	pQueue->currentElementCount--;
	return (retNode);
}

queueNode* peekLQ(Linkedqueue* pQueue)
{
	if (isLinkedQueueEmpty(pQueue))
		return (NULL);
	return (pQueue->pFrontNode);
}

void deleteLinkedQueue(Linkedqueue* pQueue)
{
	queueNode	*tmp;

	if (!isLinkedQueueEmpty(pQueue))
	{
		while (pQueue->currentElementCount > 0)
		{	
			tmp = dequeueLQ(pQueue);
			free(tmp);
		}
	}
	free(pQueue);
	memset(pQueue, 0, sizeof(Linkedqueue));
}

int isLinkedQueueFull(Linkedqueue* pQueue)
{
	return (FALSE);
}

int isLinkedQueueEmpty(Linkedqueue* pQueue)
{
	return (pQueue->currentElementCount == 0);
}
