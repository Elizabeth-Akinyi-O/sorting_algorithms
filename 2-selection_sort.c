#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array of numbers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t a, index;
	int temp, swap, flag = 0;
	/* flag-tracks whether any swaps have ocurred during each pass */
	/* temp - index of the current minimum element found so far */

	if (array == NULL)
		return;
	for (a = 0; a < size; a++)
	{
		temp = a;
		flag = 0;
		for (index = a + 1; index < size; index++)
		{
			if (array[temp] > array[index])
			{
				temp = index;
				flag += 1;
			}
		}
		swap = array[a];
		array[a] = array[temp];
		array[temp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
