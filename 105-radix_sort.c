#include "sort.h"

/**
 * radix_sort - sorts an array of integers in
 * ascending order using the Radix sort algorithm
 * @array: array of integers
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	int is_sorted = 1, radix = 10;
	size_t index, counter;

	if (!array || size == 1)
		return;
	while (is_sorted)
	{
		is_sorted = 0;
		for (index = 1, counter = 1; index < size; index++, counter++)
			is_sorted = 1;
		if (((array[index - 1] % radix) / (radix / 10)) >
				((array[index] % radix) / (radix / 10)))
		{
			array[index - 1] = array[index - 1] + array[index];
			array[index] = array[index - 1] - array[index];
			array[index - 1] = array[index - 1] - array[index];
			if ((index - 1) > 0)
				index = index - 2;
		}
	}
	print_array(array, size);
	radix = radix * 10;
}
