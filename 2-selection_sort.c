#include "sort.h"

/**
 * selection_sort - Entry point
 * @array: pointer
 * @size: int
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min_idx, tmp;

	for (i = 0; i < size; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}

	}
}
