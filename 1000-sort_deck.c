#include "deck.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: positive byte diff if s1 > s2,
 * 0 if s1 == s2, negative byte diff if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - gets the numerical valueof a card
 * @card: apointer to a deck_node_t card
 *
 * Return: numerical value of the card
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - sorts a deck of cards from spades to diamonds
 * @deck: pointer to the head of a deck_node_t doubly linked list
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iterator, *insert, *temp;

	for (iterator = (*deck)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
		insert = iterator->prev;
		while (insert != NULL && insert->card->kind > iterator->card->kind)
		{
			insert->next = iterator->next;
			if (iterator->next != NULL)
				iterator->next->prev = insert;
			iterator->prev = insert->prev;
			iterator->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iterator;
			else
				*deck = iterator;
			insert->prev = iterator;
			insert = iterator->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - sorts a deck of cards sorted from spades
 * to diamondsfrom ace to king
 * @deck: pointer to the head of a deck_node_t doubly linked list
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iterator, *insert, *temp;

	for (iterator = (*deck)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
		insert = iterator->prev;
		while (insert != NULL &&
				insert->card->kind == iterator->card->kind &&
				get_value(insert) > get_value(iterator))
		{
			insert->next = iterator->next;
			if (iterator->next != NULL)
				iterator->next->prev = insert;
			iterator->prev = insert->prev;
			iterator->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iterator;
			else
				*deck = iterator;
			insert->prev = iterator;
			insert = iterator->prev;
		}
	}
}

/**
 * sort_deck - sorts a deck of cards from ace to king
 * and from spades to diamonds
 * @deck: pointer to the head of a deck_node_t doubly linked list
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
