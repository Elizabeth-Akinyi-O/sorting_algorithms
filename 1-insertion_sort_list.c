#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}

}

/**
 * swap_node - swaps a node
 * @node: node
 * @list: node list
 *
 * Return: pointer of the current node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *pred = node->prev, *curr = node;
	/* pred - predecessor node, curr - current node */
	pred->next = curr->next;
	if (curr->next)
		curr->next->prev = pred;
	curr->next = pred;
	curr->prev = pred->prev;
	pred->prev = curr;
	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;
	return (curr);
}
