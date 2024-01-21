#include "monty.h"


/**
 * mul_instr - multiplies the top two elements of a stack.
 * @stack: the stack.
 * @ln: bad line
 * Return: nothing
 */
void mul_instr(stack_t **stack, unsigned int ln)
{
	stack_t *curr_node, *prev_node;
	char *err_msg = "L%u: can't mul, stack too short\n";

	if ((stack == NULL) || (*stack == NULL))
	{
		fprintf(stderr, err_msg, ln);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
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
		prev_node->n *= curr_node->n;
		prev_node->next = NULL;
		free(curr_node);
	}
}



/**
 * div_instr - div the top two elements of a stack.
 * @stack: the stack.
 * @ln: misbehaving line
 * Return: nothing
 */
void div_instr(stack_t **stack, unsigned int ln)
{
	stack_t *curr_node, *prev_node;
	char *err_msg = "L%u: can't div, stack too short\n";
	char *err_zerr = "L%u: division by zero\n";

	if ((stack == NULL) || (*stack == NULL))
	{
		fprintf(stderr, err_msg, ln);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
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
		if (curr_node->n == 0)
		{
			fprintf(stderr, err_zerr, ln);
			exit(EXIT_FAILURE);
		}
		prev_node->n /= curr_node->n;
		prev_node->next = NULL;
		free(curr_node);
	}
}



/**
 * mod_instr - mod the top two elements of a stack.
 * @stack: the stack.
 * @ln: line which spawned error
 * Return: nothing
 */
void mod_instr(stack_t **stack, unsigned int ln)
{
	stack_t *curr_node, *prev_node;
	char *err_msg = "L%u: can't mod, stack too short\n";
	char *err_zerr = "L%u: division by zero\n";

	if ((stack == NULL) || (*stack == NULL))
	{
		fprintf(stderr, err_msg, ln);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
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
		if (curr_node->n == 0)
		{
			fprintf(stderr, err_zerr, ln);
			exit(EXIT_FAILURE);
		}
		prev_node->n %= curr_node->n;
		prev_node->next = NULL;
		free(curr_node);
	}
}
