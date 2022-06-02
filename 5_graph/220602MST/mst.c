#include "mst.h"

LinkedGraph	*mstKruskal(LinkedGraph *pGraph)
{
	LinkedGraph *mst = createLinkedGraph(pGraph->maxVertexCount);
	HeapNode *Min_node;
	HeapBucket *minheaptree = orderedge(pGraph);


	for (int i = 0; i < 7; i++)
	{
		Min_node = deleteMinHeapElement(minheaptree);
	
		if (DFS_cycle_check(Min_node->fromvertexID, Min_node->tovertexID, mst) == FALSE)
		{
			if (mst->pVertex[Min_node->fromvertexID] == NOT_USED)
				addVertexAG(mst, Min_node->fromvertexID);
			if (mst->pVertex[Min_node->tovertexID] == NOT_USED)
				addVertexAG(mst, Min_node->tovertexID);
			addEdgewithWeightAG(mst, Min_node->fromvertexID, Min_node->tovertexID, Min_node->data);
		}
	}
	return mst;
}

HeapBucket *orderedge(LinkedGraph *pGraph)
{
	HeapBucket *ret = createHeap(7); // 간선개수 만드는 함수 필요 !!

	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
		{
			ListNode *curr;
			curr = pGraph->ppAdjEdge[i]->headerNode.pLink;

			while (curr)
			{
				int vertexID = curr->data.vertexID;
				
				if (pGraph->graphType == GRAPH_DIRECTED
					|| (pGraph->graphType == GRAPH_UNDIRECTED && i < vertexID))
				{
					HeapNode element = {0, };
					element.data = curr->data.weight;
					element.fromvertexID = i;
					element.tovertexID = curr->data.vertexID;
					addMinHeapElement(ret, element);
				}
				curr = curr->pLink;
			}
		}
	}
	return ret;
}
