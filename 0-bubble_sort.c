#include "sort.h"
/**
 * bubble_sort - bubble sorts an array
 * array: array to sort
 */
void bubble_sort(int *array, size_t size)
{
	int flag, temp;
	size_t i = 0, j = 0, n = size;

	if (size == 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, n);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
