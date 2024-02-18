#include "sort.h"

/**
 * bubble_sort -  sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int temp;

	for (a = 0; a < size; a++)
		for (b = 0; b < size - 1; b++)
			if (array[b] > array[b + 1])
			{
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				print_array(array, size);
			}
}
