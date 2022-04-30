#include "arrayqueue.h"

int main()
{
    ArrayQueue      *queue;
    ArrayQueueNode  element;

    
    queue = createArrayQueue(5);
    for (int i = 0; i < 5; i++)
    {
        element.data = 'A' + i;
        enqueueAQ(queue, element);
    }
    printf("isArrayQueueFull? [%d]\n", isArrayQueueFull(queue));
    printf("isArrayQueueEmpty? [%d]\n", isArrayQueueEmpty(queue));
    for (int i = 0; i < 2; i++)
    {
        dequeueAQ(queue);
    }
    printf("PeekQueue = '%c'\n", peekAQ(queue)->data);
    element.data = 'F';
    enqueueAQ(queue, element);
    printf("PeekQueue = '%c'\n", peekAQ(queue)->data);
    displayArrayQueue(queue);
    return (0);
}