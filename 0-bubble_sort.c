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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swaps_int(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		length--;
	}
}
