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
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: A pointer to a pointer to the first node of the list
 *
 * Return: A pointer to the first node of the sorted list
 */
listint_t *insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *pos_to_change;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return (*list);

	ptr = (*list)->next;
	while (ptr != NULL)
	{
		pos_to_change = find_insert_pos(*list, ptr);
		if (pos_to_change != ptr)
		{
			(ptr->prev)->next = ptr->next;
			if (ptr->next != NULL)
			{
				(ptr->next)->prev = ptr->prev;
			}

			ptr->prev = pos_to_change->prev;
			ptr->next = pos_to_change;
			if (pos_to_change->prev != NULL)
			{
				pos_to_change->prev->next = ptr;
			}
			else
				*list = ptr;

			pos_to_change->prev = ptr;

		}
		else
			ptr = ptr->next;
	}

	return (*list);
}

/**
 * find_insert_pos - Finds the position where the current node should be
 * inserted in the sorted list
 * @head: A pointer to the first node of the list
 * @node: The current node to be inserted in the list
 *
 * Return: A pointer to the node where the current node should be inserted
 */
listint_t *find_insert_pos(listint_t *head, listint_t *node)
{
	listint_t *pos;

	pos = head;
	while (pos != node && pos->n <= node->n)
	{
		pos = pos->next;
	}

	return (pos);
}

void swap_nodes(listint_t *node_1, listint_t *node_2)
{
	listint_t *temp;

	printf("During swap\n");
	if (node_1->prev != NULL)
		node_1->prev->next = node_2;

	if (node_2->next != NULL)
		node_2->next->prev = node_1;

	printf("=> Prev: %d, Curr: %d\n",
	       node_1->n, node_2->n);
	temp = node_1->prev;
	node_1->prev = node_2;
	node_1->next = node_2->next;
	node_2->prev = temp;
	node_2->next = node_1;
	printf("Prev: %d, Curr: %d\n",
	       node_1->prev->n, node_2->next->n);
}
