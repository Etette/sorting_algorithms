#include "sort.h"

void swap_nodes(listint_t **list, listint_t **a, listint_t **b, int *s);
void css_recurse(listint_t **l, listint_t *curr, listint_t *stop, int dir);

/**
 * cocktail_sort_list - sort doubly-linked list with cocktail method
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	/*cover NULL lists or lists < 2 nodes */
	if (!list || !(*list) || !(*list)->next)
		return;

	css_recurse(&(*list), *list, NULL, 1);
}

/**
 * css_recurse - recursive sorting component of cocktail shaker sort
 * @l: list being sorted
 * @curr: current node of list
 * @stop: last sorted node
 * @dir: direction of parse
 */
void css_recurse(listint_t **l, listint_t *curr, listint_t *stop, int dir)
{
	int swap = 0;
	listint_t *tmp = NULL, *next_stop = NULL;

	if (stop != NULL)
		next_stop = curr;

	if (dir == 1)
	{
		do {
			if (curr->n > curr->next->n)
			{
				tmp = curr->next;
				swap_nodes(&(*l), &curr, &tmp, &swap);
			}
			else
				curr = curr->next;
		} while (curr->next != stop);
		if (swap)
			css_recurse(&(*l), curr->prev, next_stop, -1);
	}
	else /*dir == -1*/
	{
		while (curr->prev != stop)
		{
			if (curr->n < curr->prev->n)
			{
				tmp = curr->prev;
				swap_nodes(&(*l), &tmp, &curr, &swap);
			}
			else
				curr = curr->prev;
		}
		if (swap)
			css_recurse(&(*l), curr->next, next_stop, 1);
	}
}

/**
 * swap_nodes - swap two nodes
 * @list: list
 * @a: left node
 * @b: right node
 * @s: pointer to flag
 */
void swap_nodes(listint_t **list, listint_t **a, listint_t **b, int *s)
{
	(*a)->next = (*b)->next;
	(*b)->prev = (*a)->prev;
	if ((*b)->next)
		(*b)->next->prev = (*a);
	if ((*a)->prev)
		(*a)->prev->next = (*b);
	(*b)->next = (*a);
	(*a)->prev = (*b);
	if (*a == *list)
		*list = *b;

	print_list(*list);
	*s = 1;
}
