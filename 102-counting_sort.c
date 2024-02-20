#include "sort.h"

/**
 * counting_sort - sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int a, max_val;
	int *occurrences = NULL, *array_clone = NULL; /* array copy */
	size_t b, temp, total = 0;

	if (array == NULL || size < 2)
		return;
	array_clone = malloc(sizeof(int) * size);
	if (array_clone == NULL)
		return;
	for (b = 0, max_val = 0; b < size; b++)
	{
		array_clone[b] = array[b];
		if (array[b] > max_val)
			max_val = array[b];
	}
	occurrences = malloc(sizeof(int) * (max_val + 1));
	if (occurrences == NULL)
	{
		free(array_clone);
		return;
	}
	for (a = 0; a <= max_val; a++)
		occurrences[a] = 0;
	for (b = 0; b < size; b++)
		occurrences[array[b]] += 1;
	for (a = 0; a <= max_val; a++)
	{
		temp = occurrences[a];
		occurrences[a] = total;
		total += temp;
	}
	for (b = 0; b < size; b++)
	{
		array[occurrences[array_clone[b]]] = array_clone[b];
		occurrences[array_clone[b]] += 1;
	}
	print_array(occurrences, max_val + 1);
	free(occurrences);
	free(array_clone);
}
