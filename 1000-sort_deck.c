#include "deck.h"

void swap_dnodes(deck_node_t **list, deck_node_t **a, deck_node_t **b, int *s);
void suit_sort(deck_node_t **l, deck_node_t *curr, deck_node_t *stop, int dir);
deck_node_t *rs(deck_node_t **l, deck_node_t *curr, deck_node_t *, int);
int ranktoi(const char *rank_str);

/**
 * sort_deck - sort deck of cards by suit and rank
 * @deck: deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *next_suit;

	if (!deck || !(*deck) || !(*deck)->next)
		return;

	suit_sort(deck, *deck, NULL, 1);
	next_suit = *deck;
	while (next_suit)
	{
		next_suit = rs(deck, next_suit, NULL, 1);
	}
}

/**
 * suit_sort - recursively sort deck by suit using cocktail shaker scheme
 * @l: list being sorted
 * @curr: current node
 * @stop: last sorted node
 * @dir: direction of parse
 */
void suit_sort(deck_node_t **l, deck_node_t *curr, deck_node_t *stop, int dir)
{
	int swap = 0;
	deck_node_t *tmp = NULL, *next_stop = NULL;

	if (stop != NULL)
		next_stop = curr;

	if (dir == 1)
	{
		do {
			if (curr->card->kind > curr->next->card->kind)
			{
				tmp = curr->next;
				swap_dnodes(&(*l), &curr, &tmp, &swap);
			}
			else
				curr = curr->next;
		} while (curr->next != stop);

		if (swap)
			suit_sort(&(*l), curr->prev, next_stop, -1);
	}
	else
	{
		while (curr->prev != stop)
		{
			if (curr->card->kind < curr->prev->card->kind)
			{
				tmp = curr->prev;
				swap_dnodes(&(*l), &tmp, &curr, &swap);
			}
			else
				curr = curr->prev;
		}
		if (swap)
			suit_sort(&(*l), curr->next, next_stop, 1);
	}
}

/**
 * rs - recursively sort deck by rank
 * @l: list to sort
 * @curr: current node in the list
 * @stop: last sorted node
 * @dir: direction of parse
 * Return: pointer to next suit
 */
deck_node_t *rs(deck_node_t **l, deck_node_t *curr, deck_node_t *stop, int dir)
{
	int swap = 0;
	deck_node_t *tmp = NULL, *next_stop = NULL, *next_suit = NULL;

	if (stop != NULL)
		next_stop = curr;

	if (dir == 1)
	{
		do {
			if (ranktoi(curr->card->value) > ranktoi(curr->next->card->value))
			{
				tmp = curr->next;
				swap_dnodes(&(*l), &curr, &tmp, &swap);
			}
			else
				curr = curr->next;
		} while (curr->next != stop && curr->card->kind == curr->next->card->kind);
		if (swap)
			rs(&(*l), curr->prev, next_stop, -1);
		if (curr->next)
			if (curr->card->kind != curr->next->card->kind)
				next_suit = curr->next;
	}
	else
	{
		while (curr->prev != stop && curr->card->kind == curr->prev->card->kind)
		{
			if (ranktoi(curr->card->value) < ranktoi(curr->prev->card->value))
			{
				tmp = curr->prev;
				swap_dnodes(&(*l), &tmp, &curr, &swap);
			}
			else
				curr = curr->prev;
		}
		if (swap)
			rs(&(*l), curr->next, next_stop, 1);
	}
	return (next_suit);
}

/**
 * ranktoi - convert string rank to integer
 * @rank_str: string rank to convert
 * Return: integer
 */
int ranktoi(const char *rank_str)
{
	int rank_int;

	if (!rank_str)
		return (-1);
	if (strcmp(rank_str, "Ace") == 0)
		rank_int = 1;
	else if (strcmp(rank_str, "Jack") == 0)
		rank_int = 11;
	else if (strcmp(rank_str, "Queen") == 0)
		rank_int = 12;
	else if (strcmp(rank_str, "King") == 0)
		rank_int = 13;
	else
	{
		rank_int = atoi(rank_str);
		if (rank_int < 1 || rank_int > 10)
			return (-1);
	}
	return (rank_int);
}

/**
 * swap_dnodes - swap two nodes
 * @list: list
 * @a: left node
 * @b: right node
 * @s: pointer to flag
 */
void swap_dnodes(deck_node_t **list, deck_node_t **a, deck_node_t **b, int *s)
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
	*s = 1;
}
