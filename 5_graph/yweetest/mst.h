#include "heap.h" //minheap 사용
#include "arraystack.h" //cycle check 시 사용
#include "graphlinkedlist.h"
#include "dfs.h" //cycle check 시 사용
#include <limits.h>


LinkedGraph	*mstKruskal(LinkedGraph *pGraph);
HeapBucket *orderedge(LinkedGraph *pGraph);


typedef struct GraphEdgeType
{
	int fromvertexID;		// Tail 노드 ID
	int tovertexID;			// Head 노드 ID
	int	weight;				// 가중치
} GraphEdge;

LinkedGraph	*mstPrim(LinkedGraph *pGraph, int startvertexID);
void	getMinWeightEdge(LinkedGraph *pGraph, LinkedGraph *mst, int fromvertexID, GraphEdge *minWeightEdge);
int checkEdge(LinkedGraph *pGraph, int fromvertexID, int tovertexID);
