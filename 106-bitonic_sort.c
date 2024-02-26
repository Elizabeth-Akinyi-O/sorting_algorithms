#include "sort.h"

void swap(int *x, int *y);

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
 * bitonic_merge - sorts a bitonic sequence inside an array of integers
 * @array: array of integers
 * @size: size of the array
 * @begin: starting index of the sequence in the array to be sorted
 * @cnt: size of the sequence to sort - parameter count
 * @dir: direction to sort in
 */
void bitonic_merge(int *array, size_t size, size_t begin, size_t cnt, char dir)
{
	size_t a, jump = cnt / 2;

	if (cnt > 1)
	{
		for (a = begin; a < begin + jump; a++)
		{
			if ((dir == UP && array[a] > array[a + jump]) ||
			    (dir == DOWN && array[a] < array[a + jump]))
				swap(array + a, array + a + jump);
		}
		bitonic_merge(array, size, begin, jump, dir);
		bitonic_merge(array, size, begin + jump, jump, dir);
	}
}

/**
 * bitonic_seq - converts an array of integers into a biotonic sequence
 * @array: array of integers
 * @size: size of the array
 * @begin: starting index of a block of the building bitonic sequence
 * @cnt: size of the subsequence to be sorted
 * @dir: direction to sort the bitonic sequence block in
 */
void bitonic_seq(int *array, size_t size, size_t begin, size_t cnt, char dir)
{
	size_t cut = cnt / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (cnt > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", cnt, size, str);
		print_array(array + begin, cnt);

		bitonic_seq(array, size, begin, cut, UP);
		bitonic_seq(array, size, begin + cut, cut, DOWN);
		bitonic_merge(array, size, begin, cnt, dir);

		printf("Result [%lu/%lu] (%s):\n", cnt, size, str);
		print_array(array + begin, cnt);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
