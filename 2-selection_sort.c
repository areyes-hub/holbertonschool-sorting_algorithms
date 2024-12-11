#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * selection_sort - sorts an array of integers
 * in descending order
 * @array: the array to sort
 * @size: the size of the array
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minIdx, temp;

	for (i = 0; i < size - 1; i++)
	{
		minIdx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIdx])
			{
				minIdx = j;
			}
		}
		temp = array[i];
		array[i] = array[minIdx];
		array[minIdx] = temp;
		print_array(array, size);
	}
}
