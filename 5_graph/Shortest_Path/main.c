#include "shortest_path.h"

int main()
{
	LinkedGraph *pGraph = createLinkedGraph(6);

	addVertexAG(pGraph, 0);
	addVertexAG(pGraph, 1);
	addVertexAG(pGraph, 2);
	addVertexAG(pGraph, 3);
	addVertexAG(pGraph, 4);
	addVertexAG(pGraph, 5);

	addEdgewithWeightAG(pGraph, 0, 1, 2);
	addEdgewithWeightAG(pGraph, 0, 3, 1);
	addEdgewithWeightAG(pGraph, 1, 3, 2);
	addEdgewithWeightAG(pGraph, 1, 2, 3);
	addEdgewithWeightAG(pGraph, 3, 4, 1);
	addEdgewithWeightAG(pGraph, 4, 5, 2);
	addEdgewithWeightAG(pGraph, 2, 5, 5);

	int *path = dijkstra(pGraph, 5);
	for (int i = 0; i < 6; i++)
		printf("[%d] : %d\n", i, path[i]);
	return 0;
}
