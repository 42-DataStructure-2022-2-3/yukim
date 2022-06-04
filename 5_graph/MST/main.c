#include "mst.h"

int main()
{
	LinkedGraph *pGraph = createLinkedGraph(6);

	addVertexAG(pGraph, 0);
	addVertexAG(pGraph, 1);
	addVertexAG(pGraph, 2);
	addVertexAG(pGraph, 3);
	addVertexAG(pGraph, 4);
	addVertexAG(pGraph, 5);

	addEdgewithWeightAG(pGraph, 0, 1, 4);
	addEdgewithWeightAG(pGraph, 0, 2, 3);
	addEdgewithWeightAG(pGraph, 1, 2, 2);
	addEdgewithWeightAG(pGraph, 2, 3, 1);
	addEdgewithWeightAG(pGraph, 3, 4, 1);
	addEdgewithWeightAG(pGraph, 3, 5, 5);
	addEdgewithWeightAG(pGraph, 4, 5, 6);

	LinkedGraph *mst = mstKruskal(pGraph);
	displayLinkedGraph(mst);
	return 0;
}