#include "shell_sort.h"

void print_value_array(int *value, int count)
{
	for (int i = 0; i < count; i++)
		printf("%d  ", value[i]);
	printf("\n");
}

void shell_sort(int *value, int count)
{
	int gap = count / 2 + 1;
	int i, j, tmp;

	while (gap)
	{
		for (i = 0; i + gap < count; i++)
		{
			for (j = i + gap; j < count; j += gap);
			{
				tmp = value[j];
				int k = j - gap;
				while (k > )
			}
		}
		gap = gap / 2 + 1;
	}
}
