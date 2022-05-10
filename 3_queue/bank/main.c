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

	for (int i = 1; i <= 3; i++)
		insertCustomer(i, i, pArrivalQueue);
	while (currentTime < 100)
	{
		processArrival(currentTime, pArrivalQueue, pWaitQueue);
		processServiceNodeEnd(currentTime, pServiceNode, &serviceUserCount, &totalWaitTime);
		pServiceNode = processServiceNodeStart(currentTime, pWaitQueue);
		printWaitQueueStatus(currentTime, pWaitQueue);
		currentTime++;
	}
	// printReport(pWaitQueue, serviceUserCount, totalWaitTime);
	return (0);
}
