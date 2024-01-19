#include "lists.h"

/**
 * insert_dnodeint_at_index - self-explanatory.
 * @h: ptr to head of list or somn
 * @idx: in the new list, our node has index idx if this works.
 * @n: number
 * Return: pointer to new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *new_node, *crnt_node;

	if (h == NULL)
		return (NULL);
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->n = n;

	if (*h == NULL)
	{
		*h = new_node;
		return (new_node);
	}
	crnt_node = *h;
	while (crnt_node->prev != NULL)
		crnt_node = crnt_node->prev;
	for (i = 0 ; crnt_node != NULL ; ++i)
	{
		if (i == idx)
		{
			new_node->prev = (crnt_node->prev);
			new_node->next = crnt_node;
			if (crnt_node->prev != NULL)
				(crnt_node->prev)->next = new_node;
			crnt_node->prev = new_node;
			return (new_node);
		}
		crnt_node = crnt_node->next;
	}
	free(new_node);

	return (NULL);
}
