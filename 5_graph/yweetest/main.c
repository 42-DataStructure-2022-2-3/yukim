#include "shortestpath.h"

int main()
{
    LinkedGraph *pGraph = createLinkedGraph(6);

    addVertexLG(pGraph, 0);
    addVertexLG(pGraph, 1);
    addVertexLG(pGraph, 2);
    addVertexLG(pGraph, 3);
    addVertexLG(pGraph, 4);
    addVertexLG(pGraph, 5);

    addEdgewithWeightLG(pGraph, 0, 1, 1 );
    addEdgewithWeightLG(pGraph, 0, 2, 4);
    addEdgewithWeightLG(pGraph, 1, 2, 2);
    addEdgewithWeightLG(pGraph, 2, 3, 1);
    addEdgewithWeightLG(pGraph, 3, 4, 8);
    addEdgewithWeightLG(pGraph, 3, 5, 3);
    addEdgewithWeightLG(pGraph, 4, 5 , 4);

    int **path = floyd(pGraph);
    for (int i = 0; i < pGraph->currentVertexCount; i++)
    {
        for (int j = 0; j < pGraph->currentVertexCount; j++)
        {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
    return 0;
}
