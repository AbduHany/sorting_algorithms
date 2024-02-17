#include "sort.h"

/**
 * move_backward - moves backwards and performs swapping in the shaker algorithm.
 * @swapflag: the flag that should be changed if a swap took place.
 * @comp1: pointer to first node to be compared and swapped if needed.
 * @comp2: pointer to second node to be compared and swapped if needed.
 * @list: double pointer to the head of the list to be sorted.
 *
 * Return: void.
 */
void move_backward(bool *swapflag, listint_t **comp1, listint_t **comp2, listint_t **list)
{
	while ((*comp1)->prev != NULL)
	{
		if ((*comp1)->n > (*comp2)->n)
		{
			(*comp2)->prev = (*comp1)->prev;
			(*comp1)->next = (*comp2)->next;
			(*comp1)->prev = (*comp2);
			(*comp2)->next = (*comp1);
			if ((*comp1)->next)
				(*comp1)->next->prev = (*comp1);
			if ((*comp2)->prev)
				(*comp2)->prev->next = (*comp2);
			(*comp1) = (*comp2)->prev;
			print_list(*list);
			*swapflag = true;

		}
		else
		{
			*comp1 = (*comp1)->prev;
			*comp2 = (*comp2)->prev;
		}
	}
}


/**
 * move_forward - moves forward and performs swapping in the shaker algorithm.
 * @swapflag: the flag that should be changed if a swap took place.
 * @comp1: pointer to first node to be compared and swapped if needed.
 * @comp2: pointer to second node to be compared and swapped if needed.
 * @list: double pointer to the head of the list to be sorted.
 *
 * Return: void.
 */
void move_forward(bool *swapflag, listint_t **comp1, listint_t **comp2, listint_t **list)
{
	while ((*comp2)->next != NULL)
	{
		if ((*comp1)->n > (*comp2)->n)
		{
			if ((*comp1)->prev == NULL)
				*list = *comp2;
			(*comp2)->prev = (*comp1)->prev;
			(*comp1)->next = (*comp2)->next;
			(*comp1)->prev = *comp2;
			(*comp2)->next = *comp1;
			if ((*comp1)->next)
				(*comp1)->next->prev = (*comp1);
			if ((*comp2)->prev)
				(*comp2)->prev->next = *comp2;
			*comp2 = (*comp1)->next;
			print_list(*list);
			*swapflag = true;
		}
		else
		{
			*comp1 = (*comp1)->next;
			*comp2 = (*comp2)->next;
		}
	}
}

/** cocktail_sort_list - sorts a list using the cocktail shaker sort
 * algorithm.
 * @list: double pointer to the head of the list to be sorted.
 *
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapflag = true;
	listint_t *comp1, *comp2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	comp1 = *list;
	comp2 = comp1->next;
	while (swapflag == true)
	{
		swapflag = false;

		move_forward(&swapflag, &comp1, &comp2, list);
		if (swapflag == false)
			break;
		move_backward(&swapflag, &comp1, &comp2, list);
		if (swapflag == false)
			break;
	}

}
