#include "search_algos.h"
#define NOT_FOUND -1

int advanced_binary(int *array, size_t size, int value)
{
	size_t i, pivot, idx = 0;
	int aux;

	if (!array)
		return (NOT_FOUND);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i == size - 1)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
	if (size == 1 && array[0] != value)
		return (NOT_FOUND);
	pivot = (size - 1) / 2;
	if (array[pivot] == value)
	{
		if (array[pivot - 1] < value)
			return (pivot);
	}
	if (array[pivot] < value)
	{
		idx += pivot + 1;
		array += pivot + 1;
		if (size % 2 != 0)
			pivot--;
	}
	pivot++;
	aux = advanced_binary(array, pivot, value);
	if (aux != NOT_FOUND)
		return (aux + idx);
	return (NOT_FOUND);
}
