#include "monty.h"


/**
 * swap_instr - swap the top two elements of the stack.
 * @stack: the stack.
 * @ln: line number
 * Return: none.
 */
void swap_instr(stack_t **stack, unsigned int ln)
{
	stack_t *curr_node, *prev_node;
	stack_t *prev_prev_node, *next_node;
	char *err_msg = "L%d: can't swap, stack too short\n";

	if (stack != NULL)
	{
		curr_node = *stack;
		while (curr_node->next != NULL)
			curr_node = curr_node->next;
		prev_node = curr_node->prev;
		if (prev_node == NULL)
		{
			fprintf(stderr, err_msg, ln);
			exit(EXIT_FAILURE);
		}
		prev_prev_node = prev_node->prev;
		next_node = curr_node->next;
		if (prev_prev_node != NULL)
			prev_prev_node->next = curr_node;
		if (next_node != NULL)
			next_node->prev = prev_node;
		prev_node->prev = curr_node;
		prev_node->next = next_node;
		curr_node->prev = prev_prev_node;
		curr_node->next = prev_node;
	}
}



/**
 * add_instr - adds the top two elements of a stack.
 * @stack: the stack.
 * @ln: natural logarithm, base e.
 * Return: to whence ye came
 */
void add_instr(stack_t **stack, unsigned int ln)
{
	stack_t *curr_node, *prev_node;
	char *err_msg = "L%u: can't add, stack too short\n";

	if (stack != NULL)
	{
		curr_node = *stack;
		while (curr_node->next != NULL)
			curr_node = curr_node->next;
		prev_node = curr_node->prev;
		if (prev_node == NULL)
		{
			fprintf(stderr, err_msg, ln);
			exit(EXIT_FAILURE);
		}
		prev_node->n += curr_node->n;
		prev_node->next = NULL;
		free(curr_node);
	}
}



/**
 * nop_instr - does nothing.
 * @stack: plates.
 * @ln: linoleum
 * Return: nay
 */
void nop_instr(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
}
