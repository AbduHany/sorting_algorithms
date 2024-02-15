#include "sort.h"

/**
 * insertion_sort_list - This function sorts a doubly linked list using the
 * insertion sort algorithm.
 * @list: a double pointer to the head of the doubly linked list.
 *
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	unsigned long int i, j;
	listint_t *cursor1, cursor2;

	if (list == NULL || *list == NULL || *list->next == NULL)
		return;
	cursor1 = cursor2 = *list;
	while (cursor1 != NULL)
	{
		cursor1 = cursor1->next;
	}
}
