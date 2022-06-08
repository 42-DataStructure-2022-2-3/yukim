#include "shell_sort.h"

int main(void)
{
	int count = 8;
	int value[count];

	for (int i = 0; i < count; i++)
	{	
		if (i % 2)
			value[i] = i + 1 * 5;
		else		
			value[i] = -i - 3;
	}
	
	printf("Before sorting : ");
	print_value_array(value, count);

	shell_sort(value, count);
	printf("After sorting : ");
	print_value_array(value, count);
	return (count);
}
