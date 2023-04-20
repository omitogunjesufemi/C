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

/**
 * insertion_sort_list - Sort by examinig the elements
 * before it and shifting is as appropriate
 * @list: unsorted linked list
 * Return: pointer to head of linked list
 */
listint_t *insertion_sort_list(listint_t *list)
{
	listint_t *ptr, *temp, *curr_ptr, *prev_ptr;

	ptr = list;
	while(ptr != NULL)
	{
		prev_ptr = ptr->prev;
		temp = ptr->prev;
		curr_ptr = ptr;
		if (prev_ptr == NULL)
			continue;
		if (curr_ptr->n < prev_ptr->n)
			swap_nodes(prev_ptr, curr_ptr);

		ptr = ptr->next;
	}

	return (list);
}

void swap_nodes(listint_t *node_1, listint_t *node_2)
{
	listint_t *temp;

	if (node_1->prev != NULL)
		node_1->prev->next = node_2;

	if (node_2->next != NULL)
		node_2->next->prev = node_1;

	temp = node_1->prev;
	node_1->prev = node_2;
	node_2->prev = temp;
	temp = node_1->next;
	node_1->next = node_2->next;
	node_2->next = temp;
}
