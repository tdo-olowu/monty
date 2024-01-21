#include "monty.h"

/**
 * new_stack - initialises the instruction stack
 * Return: pointer to the head of stack.
 */
stack_t *new_stack(void)
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: Insufficient memory\n");
	}

	return (stack);
}


/**
 * stack_append - add node to end of dll
 * @head: address of head of stack
 * @n: numbuh to store
 * Return: address of new tail?
 */
void stack_append(stack_t **head, int n)
{
	stack_t *new_tail, *old_tail;

	if (head != NULL)
	{
		new_tail = malloc(sizeof(stack_t));
		if (new_tail != NULL)
		{
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
		}
	}
}



/**
 * stack_memset - initialises the stack?
 * @stack: the stack to memset.
 * Return: none.
 */
void stack_memset(stack_t *stack)
{
	memset(stack, 0, sizeof(stack_t));
}



/**
 * free_stack - free the stack.
 * @stack: protecc, attacc, stacc
 * Return: nil
 */
void free_stack(stack_t *stack)
{
	stack_t *current_node, *next_node;

	if (stack != NULL)
	{
		current_node = stack;
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
