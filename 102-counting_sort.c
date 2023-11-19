#include <stdlib.h>
#include "sort.h"
/**
 * counting_sort - count sorts an array
 * @array: array to count sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *countarray, *temp, max, i = 0, count = 0, j = 0, specific_value, sizee = size, *count_array, count_v2;

	max = array[0];
	for (i = 0; i < sizee; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	countarray = malloc(sizeof(int) * (max + 1));
	if (!countarray)
		return;
	count_array = malloc(sizeof(int) * (max + 1));
	if (!count_array)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	for (i = 0; i < sizee; i++)
		temp[i] = array[i];
	for (i = 0; i <= max; i++)
	{
		count_v2 = 0;
		specific_value = i;
		for (j = 0; j < sizee; j++)
		{
			if (array[j] == specific_value)
			{
				count += 1;
				count_v2 += 1;
			}
		}
		countarray[i] = count;
		count_array[i] = count_v2;
	}
	print_array(countarray, max + 1);
	for (i = 1; i <= max; i++)
		count_array[i] = count_array[i - 1] + count_array[i];
	for (i = (sizee - 1); i >= 0; --i)
	{
		array[count_array[temp[i]] - 1] = temp[i];
		count_array[temp[i]] = count_array[temp[i]] - 1;
	}
	free(temp);
	free(countarray);
	free(count_array);
}
