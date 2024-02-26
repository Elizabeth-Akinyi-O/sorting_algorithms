#include "sort.h"

/**
 * swap - swaps two integers
 * @x: first integer
 * @y: second integer
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * hoare_partition - orders a subset of an array of integers according
 * to the hoare partition scheme
 * @array: the array of integers
 * @low: starting integer
 * @high: ending integer
 * @size: size of the array
 *
 * Return: final partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, first, last;

	pivot = array[high];
	for (first = low - 1, last = high + 1; first < last;)
	{
		do {
			first++;
		} while (array[first] < pivot);
		do {
			last--;
		} while (array[last] > pivot);

		if (first < last)
		{
			swap(array + first, array + last);
			print_array(array, size);
		}
	}
	return (first);
}

/**
 * hoare_quick_sort - sorts an array recursively
 * using the quick sort algotrithm
 * @array: array of integers to be sorted
 * @high: highest (ending) value of the array
 * @low: lowest (starting) value of the array
 * @size: size of the array
 */
void hoare_quick_sort(int *array, int low, int high, size_t size)
{
	int q;

	if (high - low > 0)
	{
		q = hoare_partition(array, size, low, high);
		hoare_quick_sort(array, size, low, q - 1);
		hoare_quick_sort(array, size, q, high);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_quick_sort(array, size, 0, size - 1);
}
