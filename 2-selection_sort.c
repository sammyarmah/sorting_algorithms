#include "sort.h"

/**
 * swaps_int - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swaps_int(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min_v;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_v = array + i;
		for (j = i + 1; j < size; j++)
			min_v = (array[j] < *min_v) ? (array + j) : min_v;

		if ((array + i) != min_v)
		{
			swaps_int(array + i, min_v);
			print_array(array, size);
		}
	}
}
