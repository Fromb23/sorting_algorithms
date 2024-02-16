#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i, j, minInt, temp;

	for (i = 0; i < size - 1; i++)
	{
		minInt = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minInt])
				minInt = j;
		}
		temp = array[minInt];
		array[minInt] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
