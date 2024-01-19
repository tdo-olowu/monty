#include "lists.h"

/**
 * sum_dlistint - sums up the numbers in a linked list.
 * @head: the head of the list (we hope)
 * Return: the total, or 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int i, total;
	dlistint_t *node;

	if (head == NULL)
		return (0);

	node = head;
	while (node->prev != NULL)
		node = node->prev;
	for (total = 0, i = 0 ; node != NULL ; ++i)
	{
		total += node->n;
		node = node->next;
	}

	return (total);
}
