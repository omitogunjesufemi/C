#include "hash.h"

LinkedList *create_node(HashItem *item)
{
	LinkedList *new_node;

	new_node = malloc(sizeof(LinkedList));
	if (new_node == NULL)
	{
		return NULL;
	}
	new_node->item = item;
	new_node->next = NULL;
}

LinkedList *insert_node(LinkedList *list, HashItem *item)
{
	LinkedList *new_node;

	new_node = create_node(item);

	if (list == NULL)
	{
		list = new_node;
		return list;
	}

	while (list->next != NULL)
	{
		list = list->next;
	}

	list->next = new_node;
	return list;
}

LinkedList *delete_head_node(LinkedList *list, HashItem *item)
{
	LinkedList *temp;

	if (list == NULL)
	{
		return list;
	}

	temp = list;
	list = list->next;
	free(temp->item->key);
	free(temp->item->value);
	free(temp->item);
	free(temp);
	return list;
}

void free_linkedlist(LinkedList *list)
{
	LinkedList *temp;

	temp = list;
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp->item->key);
		free(temp->item->value);
		free(temp->item);
		free(temp);
	}
}
