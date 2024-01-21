#include "monty.h"


/**
 * push_instr - pushes an element to the stack
 * add node end stack.
 * @stack: the stack
 * @ln: the line number
 * Return: none.
 */
void push_instr(stack_t **stack, unsigned int ln)
{
	char *arg = NULL;

	if (count_args(line_tok) < 2)
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}
	arg = line_tok[1];
	if (is_an_int(arg) == NAY)
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}
	stack_append(stack, convert_to_int(arg));
}



/**
 * pall_instr - prints all the values on the stakc, starting from the top.
 * @stack: the address of the stack.
 * @ln: the line number.
 * Return: non.
 */
void pall_instr(stack_t **stack, unsigned int ln)
{
	/* BUGGY prints first in twice. */
	char *fmt = "%d\n";
	stack_t *node;
	(void)ln;

	if (stack != NULL)
	{
		node = *stack;
		if (node != NULL)
		{
			while (node->next != NULL)
				node = node->next;

			while (node->prev != NULL)
			{
				printf(fmt, node->n);
				node = node->prev;
			}
		}
	}
}



/**
 * pint_instr - print the int at top of stack, followed by newline
 * @stack: address of stack
 * @ln: the line number
 * Return: nunn
 */
void pint_instr(stack_t **stack, unsigned int ln)
{
	stack_t *node;
	char *err_msg = "L%u: can't pint, stack empty\n";

	if (stack != NULL)
	{
		node = *stack;
		if (node == NULL)
		{
			fprintf(stderr, err_msg, ln);
			exit(EXIT_FAILURE);
		}
		else
		{
			while (node->next != NULL)
				node = node->next;
			printf("%d\n", node->n);
		}
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




/**
 * pop_instr - remove top item from a stack.
 * @stack: stack.
 * @ln: line number.
 * Return: none
 */
void pop_instr(stack_t **stack, unsigned int ln)
{
	stack_t *crnt_node, *prev_node;
	char *err_msg = "L%u: can't pop an empty stack\n";

	if (stack != NULL)
	{
		crnt_node = *stack;
		if (crnt_node == NULL)
		{
			fprintf(stderr, err_msg, ln);
			exit(EXIT_FAILURE);
		}
		while (crnt_node->next != NULL)
			crnt_node = crnt_node->next;
		/* check if it's the only element */
		if (crnt_node->prev == NULL)
		{
			free(crnt_node);
			*stack = NULL;
		}
		else
		{
			prev_node = crnt_node->prev;
			prev_node->next = NULL;
			free(crnt_node);
		}
	}
}
