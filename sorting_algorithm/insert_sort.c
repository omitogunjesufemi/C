#include "sort.h"

/**
 * insertion_sort_array - Sort by examinig the elements
 * before it and shifting is as appropriate
 * @array: The unsorted array
 * @size: The size of the array
 * Return: pointer to sorted array
 */
int *insertion_sort_array(int *array, int size)
{
	int i, j, temp, prev_indx, curr_indx;

	temp = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (array[i] < array[i-j])
			{
				temp = array[i-j];
				array[i-j] = array[i];
				array[i] = temp;
				i -= 1;
				j -= 1;
			}
		}
	}

	return (array);
}
