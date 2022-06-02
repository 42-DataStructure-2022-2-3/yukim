#include "heap.h" //minheap 사용
#include "arraystack.h" //cycle check 시 사용
#include "graphlinkedlist.h"
#include "dfs.h" //cycle check 시 사용

LinkedGraph	*mstKruskal(LinkedGraph *pGraph);
HeapBucket *orderedge(LinkedGraph *pGraph);

