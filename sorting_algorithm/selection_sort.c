#include "sort.h"

/**
 * selection_sort_array - Repeatedly selecting the smallest element from
 * unsorted portion to sorted portion of the list
 *
 * @array: The unsorted array
 * @size: The size of the array
 * Return: pointer to sorted array
 */
int *selection_sort_array(int *array, int size)
{
	int i, j, temp, temp2, idx;

	for (i = 0; i < size - 1; i++)
	{
		temp = array[i];
		idx = i;
		for (j = i+1; j < size; j++)
		{
			if (temp > array[j])
			{
				temp = array[j];
				idx = j;
			}
		}

		if (temp <= array[i])
		{
		        array[idx] = array[i];
			array[i] = temp;
		}
	}
	return (array);
}
