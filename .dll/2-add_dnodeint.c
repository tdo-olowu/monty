#include "lists.h"

/**
 * add_dnodeint - adds a new node to start of dll
 * @head: the head of the list, we hope.
 * @n: the integer associated with the node.
 * Return: address of new element.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *temp_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->n = n;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	temp_node = *head;
	while (temp_node->prev != NULL)
		temp_node = temp_node->prev;
	temp_node->prev = new_node;
	new_node->next = temp_node;

	return (new_node);
}
