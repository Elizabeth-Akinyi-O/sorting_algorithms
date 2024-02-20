#include "sort.h"

/**
 * TopDownMerge - sorts and merges subrrays to produce a sorted array
 * @array: array of integers
 * @size: size of the array
 * @l: starting index for left sub array
 * @r: ending index for right sub array
 */
void TopDownMerge(int *array, int *l, int *r, size_t size)
{
	int a = 0, b = 0, c = 0;
	int left, right;

	left = size / 2;
	right = size - left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, left);
	printf("[right]: ");
	print_array(r, right);

	while (a < left && b < right)
	{
		if (l[a] < r[b])
			array[c++] = l[a++];
		else
			array[c++] = r[b++];
	}

	while (a < left)
		array[c++] = l[a++];

	while (b < right)
		array[c++] = r[b++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort -  sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t a, middle = 0;
	int begin[1000];
	int end[1000];

	if (array == NULL || size < 2)
		return;

	middle = size / 2;
	for (a = 0; a < middle; a++)
		begin[a] = array[a];
	for (a = middle; a < size; a++)
		end[a - middle] = array[a];

	merge_sort(begin, middle);
	merge_sort(end, size - middle);
	TopDownMerge(array, begin, end, size);
}
