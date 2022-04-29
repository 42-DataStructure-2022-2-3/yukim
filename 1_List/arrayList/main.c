#include "arraylist.h"

int	main(void)
{
	ArrayList	*pList;
	int			max;

	max = 5000;
	pList = createArrayList(max * 2);
	for (int i = 0; i < max; i++)
	{
		ArrayListNode	pNode;
		pNode.data = i * 12;
		addALElement(pList, i, pNode);
	}
	// printf("%d\n", getArrayListLength(pList));
	// removeALElement(pList, 1);
	//displayArrayList(pList);
	timeCheck(pList, max);
	return (0);
}

void	timeCheck(ArrayList *pList, int max)
{	
	ArrayListNode	*pNode;
	clock_t			start;
	clock_t			end;
	float			result;

	start = clock();
	pNode = getALElement(pList, max - 1);
	end = clock();
	result = (float)(end - start) / CLOCKS_PER_SEC;
	printf("%.10f\n", result);
}