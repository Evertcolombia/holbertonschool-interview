#include "sort.h"

/**
 * swap - swaps two values from an array
 * @array: array of integers to modify
 * @a: index a
 * @b: index b
 * @size: size of the array
 */
static void swap(int **array, size_t a, size_t b, size_t size)
{
	int temp_val = 0;

	temp_val = *(*(array) + a);
	*(*(array) + a) = *(*(array) + b);
	*(*(array) + b) = temp_val;
	print_array(*array, size);
}
/**
 * heapify - Creates a heap from the array information
 * @array: array to iterate with
 * @n: len of the array
 * @root: root index of the heap
 * @size: size of the original array to print
 */
static void heapify(int *array, size_t n, size_t root, size_t size)
{
	size_t max = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < n && array[left] > array[max])
		max = left;
	if (right < n && array[right] > array[max])
		max = right;
	if (max != root)
	{
		swap(&array, root, max, size);
		heapify(array, n, max, size);
	}
}
/**
 * heap_sort - sorts an array using a heap structure
 * @array: array of integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || !size)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array, 0, i, size);
		heapify(array, i, 0, size);
	}
}
