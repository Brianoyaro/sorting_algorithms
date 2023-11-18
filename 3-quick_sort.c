#include <stdio.h>
#include "sort.h"
/**
 * quick_sort - uses lomuto partion scheme sorter
 * @array: array to sort
 * @size: length of array
 */
void quick_sort(int *array, size_t size)
{
	size_t low, high;

	low = 0;
	high = size - 1;
	lomuto(array, low, high);
}
/**
 * lomuto - partitions an array
 * @array: array to partition
 * @low: lowest index of array
 * @high: highest index of array
 * Return: last swapped index
 */
int partition(int *array, size_t low, size_t high)
{
	int pivot = 0, temp = 0;
	size_t i = 0, j = 0;

	pivot = array[high];
	/*lowest index so far*/
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			printf("\narray[j]: %d < pivot: %d\n", array[j], pivot);
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			++i;
			print_array(array, high);
		}
	}
	/*swap highest and lowest*/
	printf("\narray[i]: %d swap with  array[high]: %d\n", array[i], array[high]);
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	print_array(array, high);
	return (i);
}
/**
 * lomuto - quicksorts an array
 * @array: array to quicksort
 * @low: lowest index of array
 * @high: highest index of array
 */
void lomuto(int *array, size_t low, size_t high)
{
	int val;

	if (low < high)
	{
		val = partition(array, low, high);
		/*lomuto(array, low, val - 1);*/
		lomuto(array, val + 1, high);
	}
}
