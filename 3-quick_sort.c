#include "sort.h"

/**
 * swap - swaps two variables
 * @n1: first to swap
 * @n2: second to swap
 */
void swap(int *n1, int *n2)
{
	int tmp = *n1;

	*n1 = *n2;
	*n2 = tmp;
}

/**
 * _partition - Lomuto partition
 * @array: array to sort
 * @l: lowest value
 * @h: highest value
 * @size: size of array
 *
 * Return: pivot
 */
int _partition(int *array, ssize_t l, ssize_t h, size_t size)
{
	ssize_t i, j;
	int pivot;

	pivot = array[h];
	i = l - 1;
	for (j = l; j < h; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[h] < array[i + 1])
	{
		swap(&array[i + 1], &array[j]);
	}
	return (i + 1);
}
/**
 * lomuto_sch - Lomuto partition scheme.
 * @array: array to be sorted
 * @l: lowest value
 * @h: highest value, pivot
 * @size: size of array
 */
void lomuto_sch(int *array, int l, int h, size_t size)
{
	int i;

	if (l < h)
	{
		i = _partition(array, l, h, size);
		lomuto_sch(array, l, i - 1, size);
		lomuto_sch(array, i + 1, h, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sch(array, 0, size - 1, size);
}
