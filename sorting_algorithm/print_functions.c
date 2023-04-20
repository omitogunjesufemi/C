#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

/**
 * print_list_reverse - Prints all the elements of a dlistint_t in reverse
 * @h: The linked list
 * Return: the number of nodes
 */
size_t print_list_reverse(listint_t *h)
{
	listint_t *ptr;
	size_t count = 0;

	ptr = h;
	if (h != NULL)
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}

		while (ptr != NULL)
		{
			if (count > 0)
				printf(", ");
			printf("%i", ptr->n);
			ptr = ptr->prev;
			count++;
		}
		printf("\n");
		return (count);
	}

	return (0);
}
