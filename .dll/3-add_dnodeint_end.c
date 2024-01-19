#include "lists.h"

/**
 * add_dnodeint_end - add node to end of dll
 * @head: address of head of list.
 * @n: numbuh to store
 * Return: address of new end.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_tail, *old_tail;

	if (head == NULL)
		return (NULL);

	new_tail = malloc(sizeof(dlistint_t));
	if (new_tail == NULL)
		return (NULL);
	new_tail->prev = NULL;
	new_tail->next = NULL;
	new_tail->n = n;

	if (*head == NULL)
		*head = new_tail;
	else
	{
		old_tail = *head;
		while (old_tail->next != NULL)
			old_tail = old_tail->next;
		old_tail->next = new_tail;
		new_tail->prev = old_tail;
	}

	return (new_tail);
}
