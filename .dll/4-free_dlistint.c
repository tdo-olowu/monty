#include "lists.h"

/**
 * free_dlistint - free a dll
 * @head: head of the list
 * Return: none.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node, *next_node;

	if (head != NULL)
	{
		current_node = head;
		while (current_node->prev != NULL)
			current_node = current_node->prev;
		next_node = NULL;
		while (current_node->next != NULL)
		{
			next_node = current_node->next;
			free(current_node);
			current_node = next_node;
		}
		free(current_node);
	}
}
