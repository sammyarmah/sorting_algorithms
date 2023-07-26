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
 * shell_sort - Sorts an array of integers in ascending order
 *              using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

    if (array == NULL || size < 2)
	    return;

    for (gap = 1; gap < (size / 3); gap = gap * 3 + 1);

    for (; gap >= 1; gap /= 3)
    {
        for (i = gap; i < size; i++)
        {
            for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
            {
                swaps_int(array + j, array + (j - gap));
            }
        }
        print_array(array, size);
    }
}
