#include "monty.h"


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
