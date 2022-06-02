#include "arraystack.h"
#include "graphlinkedlist.h"

void recur_traversal_DFS(int vertexID, LinkedGraph *pGraph);
void	traversal_DFS (int vertexID, LinkedGraph *pGraph);
int	DFS_cycle_check(int vertexID, int tovertexID, LinkedGraph *pGraph);
