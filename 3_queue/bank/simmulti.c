#include "simmulti.h"

void		insertCustomer(int arrivalTime, int processTime, Linkedqueue *pQueue)
{
	queueNode	pInsertCustomerNode;

	if (!pQueue)
		return ;
	pInsertCustomerNode.data.status = 0;
	pInsertCustomerNode.data.arrivalTime = arrivalTime;
	pInsertCustomerNode.data.serviceTime = processTime;
	pInsertCustomerNode.data.startTime = 0;
	pInsertCustomerNode.data.endTime = 0;
	enqueueLQ(pQueue, pInsertCustomerNode);
}

void		processArrival(int currentTime, Linkedqueue *pArrivalQueue, Linkedqueue *pWaitQueue)
{
	queueNode	*pCustomerNode;

	while (!isLinkedQueueEmpty(pArrivalQueue) && peekLQ(pArrivalQueue)->data.arrivalTime == currentTime)
	{
		pCustomerNode = dequeueLQ(pArrivalQueue);
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
		pServiceNode = peekLQ(pWaitQueue);
		pServiceNode->data.status = start;
		pServiceNode->data.startTime = currentTime;
		pServiceNode->data.endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
	}
	else if (peekLQ(pWaitQueue)->data.status == end)
	{
		pServiceNode = dequeueLQ(pWaitQueue);
		free(pServiceNode);
		return (NULL);
	}
	else
		pServiceNode = peekLQ(pWaitQueue);	
	return (pServiceNode);
}

queueNode*	processServiceNodeEnd(int currentTime, queueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	if (!pServiceNode || !pServiceUserCount || !pTotalWaitTime)
		return (NULL);
	if (pServiceNode->data.endTime <= currentTime)
	{
		pServiceNode->data.status = end;
		*pServiceUserCount += 1;
		*pTotalWaitTime = *pTotalWaitTime + (pServiceNode->data.endTime - pServiceNode->data.arrivalTime);
	}
	return (pServiceNode);
}

void		printSimCustomer(int currentTime, SimCustomer customer)
{
	char	*status;

	if (customer.status == arrival)
		status = "arrival";
	else if (customer.status == start)
		status = "start";
	else if (customer.status == end)
		status = "end";

	printf("___[ printSimCustomer ]___\nCurrent time : %d\n", currentTime);
	printf("Status : %s\n", status);
	printf("arrivalTime : %d\n", customer.arrivalTime);
	printf("serviceTime : %d\n", customer.serviceTime);
	printf("startTime : %d\n", customer.startTime);
	printf("endTime : %d\n\n", customer.endTime);
}

void		printWaitQueueStatus(int currentTime, Linkedqueue *pWaitQueue)
{
	queueNode	*curr;

	if (pWaitQueue)
	{
		printf("___[ printWaitQueueStatus ]___\n");
		printf("Current time : %d\n", currentTime);
		printf("Current Waiting Customer Count : %d\n\n", pWaitQueue->currentElementCount);
		// curr = peekLQ(pWaitQueue);
		// while (curr)
		// {
		// 	printSimCustomer(currentTime, curr->data);
		// 	curr = curr->pLink;
		// }
	}
}

void		printReport(Linkedqueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	printf("___[ printReport ]___\n");
	printf("serviceUserCount : %d\n", serviceUserCount);
	printf("totalWaitTime : %d\n", totalWaitTime);
	if (!isLinkedQueueEmpty(pWaitQueue))
		printf("Current Waiting Customer Count : %d\n", pWaitQueue->currentElementCount);
}
