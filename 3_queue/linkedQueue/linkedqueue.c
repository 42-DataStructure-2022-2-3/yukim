#include "linkedqueue.h"

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
	printf("+ enqueue'%c'\n", pQueue->pRearNode->data);
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
	printf("- dequeue '%c'\n", retNode->data);
	return (retNode);
}

queueNode* peekLQ(Linkedqueue* pQueue)
{
	if (isLinkedQueueEmpty(pQueue))
		return (NULL);
	printf("peekQueue = '%c'\n", pQueue->pFrontNode->data);
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

void displayLinkedQueue(Linkedqueue *pQueue)
{
	queueNode	*curr;

	if (pQueue->currentElementCount > 0)
	{
		printf("front <-[");
		curr = pQueue->pFrontNode;
		while (curr->pLink)
		{
			printf("%c", curr->data);
			if (curr->pLink)
				printf(", ");
			curr = curr->pLink;
		}
		printf("]-> rear\n");
	}
}