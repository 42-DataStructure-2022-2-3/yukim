#include "arrayqueue.h"

int main()
{
    ArrayQueue      *pQueue;
    ArrayQueueNode  element;

    
    pQueue = createArrayQueue(5);
    for (int i = 0; i < 5; i++)
    {
        element.data = 'A' + i;
        enqueueAQ(pQueue, element);
    }
    printf("isArrayQueueFull? [%s]\n", isArrayQueueFull(pQueue) ? "TRUE" : "FALSE");
    printf("isArrayQueueEmpty? [%s]\n", isArrayQueueEmpty(pQueue) ? "TRUE" : "FALSE");
    peekAQ(pQueue);
    for (int i = 0; i < 2; i++)
    {
        dequeueAQ(pQueue);
    }
    element.data = 'F';
    enqueueAQ(pQueue, element);
    
    peekAQ(pQueue);
    displayArrayQueue(pQueue);
    return (0);
}