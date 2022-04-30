#include "linkedqueue.h"

int main()
{
	Linkedqueue		*pQueue;
	queueNode		element;

	pQueue = createLinkedQueue();
	for (int i = 0; i < 5; i++)
    {
        element.data = 'A' + i;
        enqueueLQ(pQueue, element);
    }
	printf("isLinkedQueueFull? [%s]\n", isLinkedQueueFull(pQueue) ? "TRUE" : "FALSE");
    printf("isLinkedQueueEmpty? [%s]\n", isLinkedQueueEmpty(pQueue) ? "TRUE" : "FALSE");
	peekLQ(pQueue);
	for (int i = 0; i < 2; i++)
    {
        dequeueLQ(pQueue);
    }
	peekLQ(pQueue);
	displayLinkedQueue(pQueue);
	return (0);
}