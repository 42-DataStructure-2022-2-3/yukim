#include "arrayqueue.h"

int main()
{
    ArrayQueue      *queue;
    ArrayQueueNode  element;

    
    queue = createArrayQueue(5);
    for (int i = 0; i < 5; i++)
    {
        element.data = 'a' + i;
        enqueueAQ(queue, element);
    }
    for (int i = 0; i < 2; i++)
    {
        dequeueAQ(queue);
    }
    printf("isArrayQueueFull? [%d]\n", isArrayQueueFull(queue));
    printf("isArrayQueueEmpty? [%d]\n", isArrayQueueEmpty(queue));
    displayArrayQueue(queue);
    return (0);
}