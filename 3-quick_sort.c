#include "sort.h"
/**
  *swap - swap two integer
  *@array: array passed in
  *@i: the index of integer
  *@j: the index of integer
  *@size: size of the array
  *Return: void
  */
void swap(int *array, int i, int j, size_t size)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
  *partition - locate pivot and insert it to the correct index
  *@array: array passed in
  *@low: the index of lower bound in array
  *@high: the index of higher bound in array
  *@size: size of the array
  *Return: pivot index
  */
int partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
				i = i + 1;
				if (i != j)
				{
					swap (array, i, j, size);
				}
			}
			j = j + 1;
		}
	if (array[i + 1] != pivot)
	{
		swap(array, i + 1, high, size);
	}
	return (i + 1);
}

/**
  *sort_arr - sorts left / right partition recursively
  *@array: array passed in
  *@low: the index of lower bound in array
  *@high: the index of higher bound in array
  *@size: size of the array
  *Return: void
  */
void sort_arr(int  *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		/*sort left partition*/
		sort_arr(array, low, pivot - 1, size);
		/*sort right partition*/ 
		sort_arr(array, pivot + 1, high, size);
	}
}

/**
  *quick_sort - sorts an array of integers with quick sort
  *@array: array passed in
  *@size: size of the array
  *Return: void
  */
void quick_sort(int *array, size_t size)
{
	sort_arr(array, 0, size - 1, size);
}
