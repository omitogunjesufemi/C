#include "sort.h"

int main()
{
	listint_t *head;
	listint_t *new_head;

	int arr[] = {5, 20, 11, 9, 18, 14, 4, 10, 3, 13};
	size_t size = 10;
	int *array;

	printf("Insertion Sorting of Arrays\n");
	array = selection_sort_array(arr, size);
	print_array(array, size);
	printf("\n");

	int arr_1[] = {4, 12, 7, 3, 20, 10, 18, 6, 1, 15};
	array = selection_sort_array(arr_1, size);
	print_array(array, size);
	printf("\n");

	int arr_2[] = {4, 12, 7, 3, 20, 10, 18, 6, 1, 15,
	15, 12, 8, 6, 11, 13, 17, 9, 19, 1};
	size = 20;
	array = selection_sort_array(arr_2, size);
	print_array(array, size);
	printf("\n");

	int arr_3[] = {34, 123, 41, 27, 48, 72, 26, 99, 80, 70, 173, 137, 13,
		       83, 73, 177, 133, 21, 87, 23, 140, 32, 190, 69, 110,
		       52, 186, 180, 12, 8, 57, 47, 116, 65, 55, 200, 127,
		       144, 15, 6, 179, 91, 165, 54, 78, 88, 42, 181, 86, 56,
		       107, 151, 29, 66, 195, 103, 188, 97, 172, 100, 75, 164,
		       22, 33, 138, 122, 171, 136, 198, 84, 62, 174, 131, 46,
		       93, 139, 68, 37, 170, 5, 64, 196, 114, 39, 44, 117,
		       149,7, 176, 167, 120, 124, 9, 158, 152, 153, 132,
		       192, 53, 71};
	size = 100;
	array = selection_sort_array(arr_3, size);
	print_array(array, size);

/**

	printf("\n\nInsertion sort for Linked list\n");
	head = NULL;
	add_dnodeint(&head, 18);
	add_dnodeint(&head, 17);
	add_dnodeint(&head, 13);
	add_dnodeint(&head, 11);
	add_dnodeint(&head, 4);
	add_dnodeint(&head, 1);
	add_dnodeint(&head, 15);
	add_dnodeint(&head, 12);
	add_dnodeint(&head, 16);
	add_dnodeint(&head, 2);
	add_dnodeint(&head, 19);
	add_dnodeint(&head, 11);
	add_dnodeint(&head, 9);
	add_dnodeint(&head, 1);
	add_dnodeint(&head, 3);
	add_dnodeint(&head, 20);
	print_list(head);
	print_list_reverse(head);

	new_head = insertion_sort_list(&head);
	print_list(new_head);
	print_list_reverse(new_head);

*/
	return (0);
}
