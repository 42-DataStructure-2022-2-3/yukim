#include "simmulti.h"

int main()
{
	Linkedqueue	*pArrivalQueue;
	Linkedqueue	*pWaitQueue;
	int			currentTime;
	queueNode	*pServiceNode;
	int serviceUserCount, totalWaitTime = 0;

	pArrivalQueue = createLinkedQueue();
	pWaitQueue = createLinkedQueue();
	currentTime = 0;
	pServiceNode = NULL;

	insertCustomer(0, 3, pArrivalQueue);
	insertCustomer(2, 2, pArrivalQueue);
	insertCustomer(4, 1, pArrivalQueue);
	insertCustomer(6, 1, pArrivalQueue);
	insertCustomer(8, 3, pArrivalQueue);
	
	while (currentTime < 10)
	{
		processArrival(currentTime, pArrivalQueue, pWaitQueue);
		processServiceNodeEnd(currentTime, pServiceNode, &serviceUserCount, &totalWaitTime);
		pServiceNode = processServiceNodeStart(currentTime, pWaitQueue);
		printWaitQueueStatus(currentTime, pWaitQueue);
		currentTime++;
	}
	// printReport(pWaitQueue, serviceUserCount, totalWaitTime);
	// deleteLinkedQueue(pArrivalQueue);
	// deleteLinkedQueue(pWaitQueue);
	return (0);
}
