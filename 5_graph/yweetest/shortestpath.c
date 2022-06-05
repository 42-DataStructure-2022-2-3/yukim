#include "shortestpath.h"
#include "heap.h"

int *dijkstra(LinkedGraph *pGraph, int startvertexID)
{
    int *path = calloc(pGraph->maxVertexCount, sizeof(int));
    int INF = 99999;

    HeapBucket *priorityQ = createHeap(pGraph->maxVertexCount);
    ListNode *curr;

    for (int i = 0; i < pGraph->maxVertexCount; i++)
        path[i] = INF;
    path[startvertexID] = 0;

    HeapNode element;
    element.tovertexID = startvertexID;
    element.data = 0;
    addMinHeapElement(priorityQ, element);
    while (!isHeapEmpty(priorityQ))
    {
        HeapNode *popnode = deleteMinHeapElement(priorityQ);
        int fromvertexID = popnode->tovertexID;

        curr = pGraph->ppAdjEdge[fromvertexID]->headerNode.pLink;
        while (curr)
        {
            if (path[curr->data.vertexID] > path[fromvertexID] + curr->data.weight)
            {
                element.data = curr->data.weight;
                element.tovertexID = curr->data.vertexID;
                path[curr->data.vertexID] = path[fromvertexID] + curr->data.weight;
                addMinHeapElement(priorityQ, element);
            }
            curr = curr->pLink;
        }
    }
    return path;
}
