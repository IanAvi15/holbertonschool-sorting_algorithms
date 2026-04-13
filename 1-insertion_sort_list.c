#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node: Pointer to the node to swap with its previous node
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev;

	prev = node->prev;

	if (prev->prev)
		prev->prev->next = node;
	else
		*list = node;

	if (node->next)
		node->next->prev = prev;

	node->prev = prev->prev;
	prev->next = node->next;
	node->next = prev;
	prev->prev = node;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using
 * the Insertion sort algorithm
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			swap_nodes(list, current);
			print_list(*list);
		}
		current = current->next;
	}
}
