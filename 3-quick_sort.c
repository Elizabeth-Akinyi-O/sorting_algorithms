#include "sort.h"

void swap(int *x, int *y);
int lomuto_partition(int *array, int low, int high, size_t size);
void lomuto_quick_sort(int *array, int high, int low, size_t size);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - partitions an array and pivot as the last element
 * @array: the array of integers
 * @high: starting integer
 * @low: ending integer
 * @size: size of the array
 *
 * Return: index of pivot (int)
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int *pivot, first, last;

	pivot = array + high;
	for (first = last = low; last < high; last++)
	{
		if (array[last] <= *pivot)
		{
			if (first < last)
			{
				swap(array + last, array + first);
				print_array(array, size);
			}
			first++;
		}
	}

	if (array[first] > *pivot)
	{
		swap(array + first, pivot);
		print_array(array, size);
	}
	return (first);
}

/**
 * lomuto_quick_sort - sorts an array recursively
 * using the quick sort algotrithm
 * @array: array of integers to be sorted
 * @high: highest value of the array
 * @low: lowest value of the array
 * @size: size of the array
 */
void lomuto_quick_sort(int *array, int high, int low, size_t size)
{
	int q;

	if (high - low > 0)
	{
		q = lomuto_partition(array, low, high, size);
		lomuto_quick_sort(array, low, q - 1, size);
		lomuto_quick_sort(array, q + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using lomuto partitioning
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quick_sort(array, 0, size - 1, size);
}
