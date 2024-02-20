#include "sort.h"

void quick_sort(int *array, size_t size)
{
	int pivot_index;

	if (size <= 1)
		return;

	pivot_index = partition(array, 0 , size - 1);
	quick_sort(array, pivot_index);
	quick_sort(array + pivot_index + 1, size - (pivot_index + 1));
	print_array(array, size);
}

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);

	return (i + 1);
}
