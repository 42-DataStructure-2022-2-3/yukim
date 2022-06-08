#include "insertion_sort.h"

void print_value_array(int *value, int count)
{
	for (int i = 0; i < count; i++)
		printf("%d  ", value[i]);
	printf("\n");
}

void insertion_sort(int *value, int count)
{
	int tmp, i, j;
		
	// value[0]은 정렬된 상태
	for (i = 1; i < count; i++)
	{
		tmp = value[i];
		j = i;
		while (j > 0)
		{
			if (tmp < value[j - 1])
			{
				value[j] = value[j - 1];
				j--;
			}
			else 
				break ;
		}
		value[j] = tmp;
		
		print_value_array(value, count);
	}
}
