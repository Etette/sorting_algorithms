#ifndef DECK_H
#define DECK_H

#include "sort.h"
#include <string.h>

/**
 * enum kind_e - enumeration of card suits
 * @SPADE: spade suit = 0
 * @HEART: heart suit = 1
 * @CLUB: club suit = 2
 * @DIAMOND: diamond suit = 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - playing card
 *
 * @value: card value
 * @kind: kind of card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - deck of cards
 * @card: pointer to card node
 * @prev: pointer to previous node
 * @next: pointer to next node
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif
