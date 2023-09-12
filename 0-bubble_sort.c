#include "sort.h"

/**
  * bubble_sort - function that sorts an array of integers with Bubble sort
  * @array: array of integers
  * @size: size of array
  * Return: void
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;	
	
	i = 0;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (i < (size - 1))
	{
		j = 0;
		/*this minimum time required for worst case of descending array*/
		while (j < (size - i - 1))
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
			j = j + 1;
		}
		i = i + 1;
	}
}
