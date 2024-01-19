#include "lists.h"

/**
 * dlistint_len - prints items in a doubly-linked list
 *
 * @h: head of dlist...or is it?
 * Return: number of nodes in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count_left = 0;
	size_t count_right = 0;
	const dlistint_t *node_left, *node_right;

	if (h == NULL)
		return (0);

	node_left = h;
	if (node_left->next != NULL)
		node_right = node_left->next;
	else
		node_right = NULL;

	while (node_left != NULL)
	{
		count_left += 1;
		node_left = node_left->prev;
	}
	while (node_right != NULL)
	{
		count_right += 1;
		node_right = node_right->next;
	}

	return (count_left + count_right);
}
