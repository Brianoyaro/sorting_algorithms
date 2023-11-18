#include "sort.h"
/**
 * quick_sort_hoare - hoare quicksorter
 * @array: array to quicksort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	int low = 0, high = size - 1;

	hoare(array, low, high, size);
}
/**
 * hoare - handles the logic of hoare quicksorting
 * @array: array to quicksort
 * @low: lowest index of array
 * @high: highest index of array
 * @size: size of array
 */
void hoare(int *array, int low, int high, size_t size)
{
	int val = 0;

	if (low < high)
	{
		val = hoare_partition(array, low, high, size);
		hoare(array, low, val, size);
		hoare(array, val + 1, high, size);
	}
}
/**
 * hoare_partition - partitions an array
 * @array: array to quicksort
 * @low: lowest index of array
 * @high: highest index of array
 * @size: size of array
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low], i = low, j = high, temp;

	while (1)
	{
		while (array[i] < pivot)
			i += 1;
		while (array[j] > pivot)
			j -= 1;
		if (i == j)
			return (j);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}
