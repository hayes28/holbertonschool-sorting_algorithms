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
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, x;
	int min, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				x = j;
				flag = 1;
			}
		}
		if ((flag == 1) && (j == size - 1))
		{
			swap(&array[x], &array[i]);
			print_array(array, size);
		}
	}
	flag = 0;
}
