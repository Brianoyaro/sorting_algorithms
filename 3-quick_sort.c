#include "sort.h"
void swap(int* one, int* two) 
{
	int temp;

	temp = *one;
	*one = *two;
	*two = temp;
} 

int partition(int *array, int start, int end, size_t size)
{
	int pivotVal, i, j;
	
	pivotVal = array[end];
	i = start;
	for (j = start; j < end; j++)
	{
		if (array[j] <= pivotVal)
		{
			swap(&array[i], &array[j]);
			/*print_array(array, size);*/
			i++;
		}
	}
	swap(&array[i], &array[end]);
	print_array(array, size);
	return (i);
}

void quickSort(int *array, int start, int end, size_t size)
{
	int pivotval;

	if (start < end)
	{
		pivotval = partition(array, start, end, size);
		quickSort(array, start, pivotval - 1, size);
		quickSort(array, pivotval + 1, end, size);
	}
}
void quick_sort(int *array, size_t size)
{
	quickSort(array, 0, size - 1, size);
}
