#include "simmulti.h"

void		insertCustomer(int arrivalTime, int processTime, Linkedqueue *pQueue)
{
	queueNode	pInsertCustomerNode;

	pInsertCustomerNode.data.arrivalTime = arrivalTime;
	pInsertCustomerNode.data.serviceTime = processTime;
	enqueueLQ(pQueue, pInsertCustomerNode);
}

void		processArrival(int currentTime, Linkedqueue *pArrivalQueue, Linkedqueue *pWaitQueue)
{
	queueNode	*pCustomerNode;

	while (!isLinkedQueueEmpty(pArrivalQueue) && peekLQ(pArrivalQueue)->data.arrivalTime == currentTime)
	{
		pCustomerNode = dequeueLQ(pArrivalQueue->pFrontNode);
		pCustomerNode->data.status = arrival;
		enqueueLQ(pWaitQueue, *pCustomerNode);
		free(pCustomerNode);
	}
}

queueNode*	processServiceNodeStart(int currentTime, Linkedqueue *pWaitQueue)
{
	queueNode	*pServiceNode;

	pServiceNode = NULL;
	if (isLinkedQueueEmpty(pWaitQueue))
		return (NULL);
	if (peekLQ(pWaitQueue)->data.status == arrival)
	{
		pServiceNode = dequeueLQ(pWaitQueue);
		pServiceNode->data.status = start;
		pServiceNode->data.startTime = currentTime;
		pServiceNode->data.endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
	}
	return (pServiceNode);
}

queueNode*	processServiceNodeEnd(int currentTime, queueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	if (!pServiceNode)
		return (NULL);
	if (pServiceNode->data.endTime <= currentTime)
	{
		pServiceNode->data.status = end;
		*pServiceUserCount++;
		*pTotalWaitTime = pServiceNode->data.endTime - pServiceNode->data.arrivalTime;
		free(pServiceNode);
	}
	return (NULL);
}

void		printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("Current time : %d\n", currentTime);
	printf("Status : %d\n", customer.status);
	printf("Current time : %d\n", customer.status);
	printf("Current time : %d\n", customer.status);
	printf("Current time : %d\n", customer.status);
	printf("Current time : %d\n", customer.status);
}

void		printWaitQueueStatus(int currentTime, Linkedqueue *pWaitQueue)
{

}

void		printReport(Linkedqueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{

}
