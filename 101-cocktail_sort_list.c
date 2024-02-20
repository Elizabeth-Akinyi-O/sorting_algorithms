#include "sort.h"

/**
 * swapp - swaps nodes in a doubly linked list
 * @head: head of the linked list
 * @node: node to be swapped
 */
void swapp(listint_t **head, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*head = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *traverser;

	if (list == NULL || *list == NULL)
		return;
	traverser = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (traverser->next != NULL)
		{
			if (traverser->next->n < traverser->n)
			{
				swapp(list, traverser);
				swapped = 1;
				print_list(*list);
			}
			else
				traverser = traverser->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (traverser->prev != NULL)
		{
			if (traverser->prev->n > traverser->n)
			{
				swapp(list, traverser->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				traverser = traverser->prev;
		}
	}
}
