#include "arraystack.h"
#include "dfs.h"
#include "graphlinkedlist.h"
#include "heap.h"

LinkedGraph *mstKruskal(LinkedGraph *pGraph);
HeapBucket *orderEdge(LinkedGraph *pGraph);
int cyclecheck(LinkedGraph *mst, int fromvertexID, int tovertexID);