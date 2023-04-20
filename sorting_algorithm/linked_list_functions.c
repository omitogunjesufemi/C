#include "sort.h"

/**
 * add_dnodeint - Adds a new node at the end of a list
 * @head: Head pointer
 * @n: Integer data
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_dnodeint(listint_t **head, const int n)
{
	listint_t *new_node, *ptr;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = new_node;
	new_node->prev = ptr;

	return (new_node);
}

/**
 * free_listint - Frees a listint_t list
 * @head: Head pointer
 */
void free_listint(listint_t *head)
{
	listint_t *ptr;

	if (head != NULL)
	{
		ptr = head;
		while (ptr != NULL)
		{
			head = head->next;
			free(ptr);
			ptr = head;
		}
	}
}
