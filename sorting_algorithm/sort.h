#ifndef _SORT_H_
#define _SORT_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/**
 * insertion_sort_array - Sort by examinig the elements
 * before it and shifting is as appropriate
 * @array: The unsorted array
 * @size: The size of the array
 * Return: pointer to sorted array
 */
int *insertion_sort_array(int *array, int size);

/**
 * selection_sort_array - Repeatedly selecting the smallest element from
 * unsorted portion to sorted portion of the list
 *
 * @array: The unsorted array
 * @size: The size of the array
 * Return: pointer to sorted array
 */
int *selection_sort_array(int *array, int size);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: A pointer to a pointer to the first node of the list
 *
 * Return: A pointer to the first node of the sorted list
 */
listint_t *insertion_sort_list(listint_t **list);

/**
 * find_insert_pos - Finds the position where the current node should be
 * inserted in the sorted list
 * @head: A pointer to the first node of the list
 * @node: The current node to be inserted in the list
 *
 * Return: A pointer to the node where the current node should be inserted
 */
listint_t *find_insert_pos(listint_t *head, listint_t *node);

/**
 * add_dnodeint - Adds a new node at the end of a list
 * @head: Head pointer
 * @n: Integer data
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_dnodeint(listint_t **head, const int n);
void swap_nodes(listint_t *node_1, listint_t *node_2);

/**
 * free_listint - Frees a listint_t list
 * @head: Head pointer
 */
void free_listint(listint_t *head);

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list);

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size);

/**
 * print_list_reverse - Prints all the elements of a dlistint_t in reverse
 * @h: The linked list
 * Return: the number of nodes
 */
size_t print_list_reverse(listint_t *h);


#endif
