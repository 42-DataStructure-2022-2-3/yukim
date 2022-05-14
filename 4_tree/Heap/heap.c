#include "heap.h"

Heap* createHeap(int maxElementCount)
{
    Heap *pHeap = calloc(sizeof(Heap), 1);
    pHeap->pElement = calloc(sizeof(HeapNode), maxElementCount + 1);
    pHeap->maxElementCount = maxElementCount;
    return (pHeap);
}

int isHeapFull(Heap* pHeap)
{
    return (pHeap->currentElementCount == pHeap->maxElementCount);
}

Heap *reallocHeap(Heap *pHeap)
{
    Heap *newHeap;

    if (!isHeapFull)
        return (pHeap);
    newHeap = realloc(pHeap, (pHeap->maxElementCount * 2) + 1);
    newHeap->maxElementCount = newHeap->maxElementCount * 2 + 1;
    return (newHeap);
}

void insertMaxHeapNode (Heap* pHeap, HeapNode element)
{
    int i;
    HeapNode *parentNode;

    if (isHeapFull(pHeap))
        pHeap = reallocHeap(pHeap);
    i = pHeap->currentElementCount + 1;
    pHeap->pElement[i] = element;
    pHeap->currentElementCount++;
    while(i != 1)
    {
        parentNode = &pHeap->pElement[i / 2];
        if ((*parentNode).data < pHeap->pElement[i].data)
        {
            HeapNode tmp = *parentNode;
            *parentNode = pHeap->pElement[i];
            pHeap->pElement[i] = tmp;
            i = i / 2;
        }
        else
            break;
    }
}

void insertMinHeapNode (Heap* pHeap, HeapNode element)
{
    int i;
    HeapNode *parentNode;

    if (isHeapFull(pHeap))
        pHeap = reallocHeap(pHeap);
    i = pHeap->currentElementCount + 1;
    pHeap->pElement[i] = element;
    pHeap->currentElementCount++;
    while(i != 1)
    {
        parentNode = &pHeap->pElement[i / 2];
        if ((*parentNode).data > pHeap->pElement[i].data)
        {
            HeapNode tmp = *parentNode;
            *parentNode = pHeap->pElement[i];
            pHeap->pElement[i] = tmp;
            // printf("tmp : %d\n",  tmp);
            // printf("parentNode : %d\n", *parentNode);
            i = i / 2;
        }
        else
            break;
    }
}

HeapNode* deleteMaxHeapNode (Heap* pHeap)
{
    HeapNode* retMaxNode;
    int i;
    int bigIndex;

    retMaxNode = calloc(1, sizeof(HeapNode));
    *retMaxNode = pHeap->pElement[1];
    i = pHeap->currentElementCount;
    pHeap->currentElementCount--;
    pHeap->pElement[1] = pHeap->pElement[i];
    memset(&pHeap->pElement[i], 0, sizeof(HeapNode));
    i = 1; 
    while (1)
    {
        if (pHeap->pElement[i * 2].data < pHeap->pElement[i * 2 + 1].data)
            bigIndex = i * 2 + 1; //rightChild
        else
            bigIndex = i * 2; // leftChild
        if (pHeap->pElement[bigIndex].data > pHeap->pElement[i].data)
        {
            HeapNode tmp;
            tmp = pHeap->pElement[bigIndex];
            pHeap->pElement[bigIndex] = pHeap->pElement[i];
            pHeap->pElement[i] = tmp;
            i = bigIndex;
        }
        else
            break;
    }
    return (retMaxNode);
}

HeapNode* deleteMinHeapNode (Heap* pHeap)
{
    HeapNode* retMinNode;
    int i;
    int minIndex;

    retMinNode = calloc(1, sizeof(HeapNode));
    *retMinNode = pHeap->pElement[1];
    i = pHeap->currentElementCount;
    pHeap->currentElementCount--;
    pHeap->pElement[1] = pHeap->pElement[i];
    memset(&pHeap->pElement[i], 0, sizeof(HeapNode));
    i = 1; 
    while (1)
    {
        if (pHeap->pElement[i * 2].data > pHeap->pElement[i * 2 + 1].data)
            minIndex = i * 2 + 1; //rightChild
        else
            minIndex = i * 2; // leftChild
        if (pHeap->pElement[minIndex].data < pHeap->pElement[i].data)
        {
            HeapNode tmp;
            tmp = pHeap->pElement[minIndex];
            pHeap->pElement[minIndex] = pHeap->pElement[i];
            pHeap->pElement[i] = tmp;
            i = minIndex;
        }
        else
            break;
    }
    return (retMinNode);
}
void deleteHeap(Heap* pHeap)
{
    free(pHeap->pElement);
    pHeap->pElement = NULL;
    free(pHeap);
    memset(pHeap, 0, sizeof(Heap));
}

void displayHeap(Heap* pHeap)
{
    // 어떻게 출력해야할까?
    // 1. 같은 레벨 출력
    // 2. 배열 순서대로 출력
    for (int i = 1; i <= pHeap->currentElementCount; i++)
    {
        printf("[%d : %d] ", i, pHeap->pElement[i].data);
    }
    printf("\n");
}
