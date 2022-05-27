#include "graphlinkedlist.h"

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph	*pGraph;

	pGraph = (LinkedGraph *)calloc(1, sizeof(LinkedGraph));

	pGraph->maxVertexCount = maxVertexCount;
	pGraph->graphType = GRAPH_UNDIRECTED;
	pGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	pGraph->pAdjEdge = (LinkedList *)calloc(maxVertexCount, sizeof(LinkedList));
	return (pGraph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph	*pGraph;

	pGraph = (LinkedGraph *)calloc(1, sizeof(LinkedGraph));

	pGraph->maxVertexCount = maxVertexCount;
	pGraph->graphType = GRAPH_DIRECTED;
	pGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	pGraph->pAdjEdge = (LinkedList *)calloc(maxVertexCount, sizeof(LinkedList));
	return (pGraph);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->pAdjEdge[i]);
	free(pGraph->pAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
	pGraph = NULL;
}

int isEmptyAG(LinkedGraph* pGraph)
{
	if (pGraph && pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

int addVertexAG(LinkedGraph* pGraph, int vertexID)// vertexIndex
{
	if (!pGraph || pGraph->pVertex[vertexID] == USED)
		return (FAIL);
	if (vertexID >= pGraph->maxVertexCount)
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

int addEdgeAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (FAIL);
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	

	ListNode element;
	element.data.vertexID = toVertexID;
	element.data.weight = 0;
	int last = pGraph->pAdjEdge[fromVertexID].currentElementCount;
	addLLElement(&pGraph->pAdjEdge[fromVertexID], last, element);

	pGraph->pAdjEdge[fromVertexID].currentElementCount++;

	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->pAdjEdge[toVertexID][fromVertexID] = 1;
	return (SUCCESS);
}
int addEdgewithWeightAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->pAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->pAdjEdge[toVertexID][fromVertexID] = weight;
	return (SUCCESS);
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph || vertexID >= pGraph->maxVertexCount)
		return (FAIL);
	return (pGraph->pVertex[vertexID] == USED);
}

int removeVertexAG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph || !checkVertexValid(pGraph, vertexID) || isEmptyAG(pGraph))
		return(FAIL);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		pGraph->pAdjEdge[i][vertexID] = 0;
	for (int j = 0; j < pGraph->maxVertexCount; j++)
		pGraph->pAdjEdge[vertexID][j] = 0;
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

int removeEdgeAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->pAdjEdge[fromVertexID][toVertexID] = 0;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->pAdjEdge[toVertexID][fromVertexID] = 0;
	return (SUCCESS);
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
	if (!pGraph)
		return ;
	printf("maxVertexCount : %d\n", pGraph->maxVertexCount);
	printf("currentVertexCout : %d\n", pGraph->currentVertexCount);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		printf("graphType : GRAPH_UNDIRECTED\n");
	else
		printf("graphType : GRAPH_DIRECTED\n");
	for(int i = 0; i < pGraph->maxVertexCount; i++)
		printf("vertex %d : %d\n", i, pGraph->pVertex[i]);
	printf("----------------------\n");
	for(int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("vertex %d : ", i);
		for (int j = 0; j < pGraph->maxVertexCount; j++)
			printf("%d ", pGraph->pAdjEdge[i][j]);	
		printf("\n");
	}
}
