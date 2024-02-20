#include "sort.h"

/**
 * heapify - builds a heap from an array (recursively)
 * @array: array of integers representing a binary tree
 * @heap: size of the heap data (no of elements)
 * @index: indexi of the current node
 * @size: size of the array
 */
void heapify(int *array, int heap, int index, int size)
{
	int max = index, left = 2 * index + 1, right = 2 * index + 2, temp;

	if (left < heap && array[left] > array[max])
		max = left;
	if (right < heap && array[right] > array[max])
		max = right;
	if (max != index)
	{
		temp = array[index], array[index] = array[max], array[max] = temp;
		print_array(array, size);
		heapify(array, heap, max, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending
 * order using the Heap sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int a = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; a >= 0; a--)
		heapify(array, size, a, size);
	for (a = size - 1; a >= 0; a--)
	{
		temp = array[0];
		array[0] = array[a];
		array[a] = temp;
		if (a > 0)
			print_array(array, size);
		heapify(array, a, 0, size);
	}
}
