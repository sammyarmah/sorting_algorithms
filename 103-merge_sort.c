#include "sort.h"

void merge_subarray(int *subarray, int *buffer, size_t front_i, size_t mid_i,
		size_t back_i);
void merge_sort_recursive(int *subarray, int *buffer, size_t front_i, size_t back_i);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - Sort a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @front_i: The front index of the array.
 * @mid_i: The middle index of the array.
 * @back_i: The back index of the array.
 */
void merge_subarray(int *subarray, int *buffer, size_t front_i, size_t mid_i,
		size_t back_i)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + front_i, mid_i - front_i);

	printf("[right]: ");
	print_array(subarray + mid_i, back_i - mid_i);

	for (i = front_i, j = mid_i; i < mid_i && j < back_i; k++)
		buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < mid_i; i++)
		buffer[k++] = subarray[i];
	for (; j < back_i; j++)
		buffer[k++] = subarray[j];
	for (i = front_i, k = 0; i < back_i; i++)
		subarray[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarray + front_i, back_i - front_i);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @front_i: The front index of the subarray.
 * @back_i: The back index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buffer, size_t front_i, size_t back_i)
{
	size_t mid_i;

	if (back_i - front_i > 1)
	{
		mid_i = front_i + (back_i - front_i) / 2;
		merge_sort_recursive(subarray, buffer, front_i, mid_i);
		merge_sort_recursive(subarray, buffer, mid_i, back_i);
		merge_subarr(subarray, buffer, front_i, mid_i, back_i);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
