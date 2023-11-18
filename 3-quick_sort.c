#include <stdio.h>
#include "sort.h"
/**
 * quick_sort - uses lomuto partion scheme sorter
 * @array: array to sort
 * @size: length of array
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	low = 0;
	high = size - 1;
	lomuto(array, low, high, size);
}
/**
 * lomuto - partitions an array
 * @array: array to partition
 * @low: lowest index of array
 * @high: highest index of array
 * Return: last swapped index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = 0, temp = 0, i = 0, j = 0;

	pivot = array[high];
	/*lowest index so far*/
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			++i;
		}
	}
	/*swap highest and lowest*/
	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}
/**
 * lomuto - quicksorts an array
 * @array: array to quicksort
 * @low: lowest index of array
 * @high: highest index of array
 */
void lomuto(int *array, int low, int high, size_t size)
{
	int val = 0;

	if ((low < high) && (high > 0) && (low >= 0))
	{
		val = partition(array, low, high, size);
		lomuto(array, low, val - 1, size);
		lomuto(array, val + 1, high, size);
	}
}
