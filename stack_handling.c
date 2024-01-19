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
		exit(EXIT_FAILURE);
	}

	return (stack);
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
