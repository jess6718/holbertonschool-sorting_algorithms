#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_idx, temp;

	if (array == NULL || size < 2)
		return;
	i = 0;
	while (i < size - 1)
	{
		/* Find the index of the minimum element in the remaining unsorted array */
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
			j++;
		}

		/* Swap the found minimum element with the current element */
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
		i++;
	}
}

