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
        //printf("popnode %d, weight %d \n", popnode->tovertexID, popnode->data);

        curr = pGraph->ppAdjEdge[fromvertexID]->headerNode.pLink;
        while (curr)
        {
            if (path[curr->data.vertexID] > path[fromvertexID] + curr->data.weight)
            {
                element.data = curr->data.weight;
                element.tovertexID = curr->data.vertexID;
                path[curr->data.vertexID] = path[fromvertexID] + curr->data.weight;
                addMinHeapElement(priorityQ, element);
                //printf("add heap info : vertexid %d , weight %d \n", element.tovertexID, element.data);
            }
            curr = curr->pLink;
        }
    }
    return path;
}

int **floyd(LinkedGraph *pGraph)
{
    int **path = calloc(pGraph->maxVertexCount, sizeof(int *));
    int INF = 99999;
    int i = 0;
    int j;
	int k;
    ListNode *curr;

    for (i = 0; i < pGraph->maxVertexCount; i++)
        path[i] = calloc(pGraph->maxVertexCount, sizeof(int));

    for (i = 0; i< pGraph->maxVertexCount; i++)
    {
        for (j = 0; j < pGraph->maxVertexCount; j++)
        {
            path[i][j] = INF;
            if (i == j)
                path[i][j] = 0;
        }
    }

    for (i = 0; i < pGraph->maxVertexCount; i++)
    {
        curr = pGraph->ppAdjEdge[i]->headerNode.pLink;
        while (curr)
        {
            path[i][curr->data.vertexID] = curr->data.weight;
            curr = curr->pLink;
        }
    }

	for (k = 0; k < pGraph->maxVertexCount; k++)
	{
		for(i = 0; i < pGraph->maxVertexCount; i++)
		{
			for (j = 0; j < pGraph->maxVertexCount; j++)
			{
				if (path[i][j] > path[i][k] + path[k][j])
					path[i][j] = path[i][k] + path[k][j];
			}
		}
	}
    return path;
}
