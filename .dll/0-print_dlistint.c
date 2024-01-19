#include "lists.h"

/**
 * print_dlistint - prints items in a doubly-linked list
 *
 * @h: head of dlist...or is it?
 * Return: number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;
	char *fmt = "%d\n";
	const dlistint_t *node;

	if (h == NULL)
		return (0);
	node = h;
	while (node->prev != NULL)
		node = node->prev;

	while (node != NULL)
	{
		printf(fmt, node->n);
		++count;
		node = node->next;
	}

	return (count);
}
