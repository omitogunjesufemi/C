#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} node_s;

node_s *add_to_empty(node_s *head, int data)
{
	node_s *new_node = malloc(sizeof(node_s));

	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	head = new_node;
	return (head);
}

node_s *add_to_start(node_s *head, int data)
{
	node_s *new_node = malloc(sizeof(node_s));

	new_node->data = data;
	head->prev = new_node;
	new_node->next = head;
	head = new_node;

	return (head);
}

node_s *add_to_end(node_s *head, int data)
{
	node_s *new_node = malloc(sizeof(node_s));
	node_s *ptr;

	ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	ptr->next = new_node;
	new_node->data = data;
	new_node->prev = ptr;
	new_node->next = NULL;

	return (head);

}

node_s *add_at_position(node_s *head, int data, int position)
{
	node_s *new_node = malloc(sizeof(node_s));
	node_s *ptr_1, *ptr_2;
	int pos = 1;

	ptr_1 = head;
	new_node->data = data;
	while (pos < position)
	{
		ptr_1 = ptr_1->next;
		pos++;
	}

	if (ptr_1->next == NULL)
	{
		ptr_1->next = new_node;
		new_node->prev = ptr_1;
		return (head);
	}

	ptr_2 = ptr_1->next;
	ptr_1->next = new_node;
	new_node->next = ptr_2;
	new_node->prev = ptr_1;
	ptr_2->prev = new_node;

	return (head);
}

node_s *delete_node_at_the_beginning(node_s *head)
{
	node_s *ptr;

	ptr = head;
	head = head->next;
	head->prev = NULL;
	free(ptr);
	ptr = NULL;

	return (head);
}

node_s *delete_node_at_the_end(node_s *head)
{
	node_s *ptr, *ptr_1;

	ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr_1 = ptr->prev;
	free(ptr);
	ptr = NULL;
	ptr_1->next = NULL;

	return (head);
}

node_s *delete_at_position(node_s *head, int position)
{
	node_s *ptr, *trailing_ptr;
	int p = 1;

	ptr = head;
	while (p < position)
	{
		ptr = ptr->next;
		p++;
	}
	trailing_ptr = ptr->prev;
	trailing_ptr->next = ptr->next;
	(ptr->next)->prev = trailing_ptr;

	return (head);
}

void free_list(node_s *head)
{
	node_s *ptr;

	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}

int main()
{
	node_s *head = NULL;
	node_s *ptr, temp;

	head = add_to_empty(head, 12);
	head = add_to_start(head, 55);
	head = add_to_end(head, 78);
	head = add_at_position(head, 100, 3);

	ptr = head;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");

	head = delete_at_position(head, 2);
	ptr = head;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
/*
	head = delete_node_at_the_end(head);
	ptr = head;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");

	head = add_to_start(head, 89);
	head = add_to_start(head, 92);

	ptr = head;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	*/
	free_list(head);
	return (0);
}
