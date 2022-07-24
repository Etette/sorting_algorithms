#include "sort.h"

void swap_nodes(listint_t **a, listint_t **b);

/**
 * insertion_sort_list - sort list in ascending order
 * @list: head of list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *curr = NULL, *prev = NULL;

	if (list && *list && (*list)->next)
	{
		tmp = (*list)->next;

		while (tmp)
		{
			curr = tmp;
			prev = tmp->prev;

			/*if values are not ascending*/
			while (prev && curr->n < prev->n)
			{
				swap_nodes(&prev, &curr);
				if (prev == *list) /*if curr now list head*/
					*list = curr;
				print_list(*list);
				prev = curr->prev;
			}
			tmp = tmp->next;
		}
	}
}

/**
 * swap_nodes - swap two nodes
 * @a: left node
 * @b: right now
 */

void swap_nodes(listint_t **a, listint_t **b)
{
	(*a)->next = (*b)->next;
	(*b)->prev = (*a)->prev;
	if ((*b)->next)
		(*b)->next->prev = (*a);
	if ((*a)->prev)
		(*a)->prev->next = (*b);
	(*b)->next = (*a);
	(*a)->prev = (*b);
}
