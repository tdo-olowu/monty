#include "lists.h"

/**
 * get_dnodeint_at_index - long function name.
 * returns the nth node of the doubly-linked-list
 * @head: head of the list.
 * @index: the index to acquire.
 * Return: pointer to node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *nth_node;
	unsigned int i;

	if (head == NULL)
		return (NULL);
	nth_node = head;
	while (nth_node->prev != NULL)
		nth_node = nth_node->prev;
	for (i = 0 ; nth_node != NULL ; ++i)
	{
		if (i == index)
			return (nth_node);
		nth_node = nth_node->next;
	}

	return (NULL);
}
