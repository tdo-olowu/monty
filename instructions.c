#include "monty.h"


/**
 * push_instr - pushes an element to the stack
 * @stack: the stack
 * @ln: the line number
 * Return: none.
 */
void push_instr(stack_t **stack, unsigned int ln)
{
	int arg = ln;

	/* check if arg is int or arg is given to push */
	stack_t *new_tail, *old_tail;

	if (stack != NULL)
	{
		new_tail = malloc(sizeof(stack_t));
		if (new_tail != NULL)
		{
			new_tail->prev = NULL;
			new_tail->next = NULL;
			new_tail->n = arg;
			if (*stack == NULL)
				*stack = new_tail;
			else
			{
				old_tail = *stack;
				while (old_tail->next != NULL)
					old_tail = old_tail->next;
				old_tail->next = new_tail;
				new_tail->prev = old_tail;
			}
		}
	}

	printf("In push on line %u\n", ln);
}



/**
 * pall_instr - prints all the values on the stakc, starting from the top.
 * @stack: the address of the stack.
 * @ln: the line number.
 * Return: non.
 */
void pall_instr(stack_t **stack, unsigned int ln)
{
	char *fmt = "%d\n";
	stack_t *node;

	if (stack != NULL)
	{
		node = *stack;
		if (node != NULL)
		{
			while (node->next != NULL)
				node = node->next;

			while (node != NULL)
			{
				printf(fmt, node->n);
				node = node->prev;
			}
		}
	}

	printf("I'm pall on line %u\n", ln);
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

	printf("I'm pint on line %u\n", ln);
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
		prev_node = crnt_node->prev;
		prev_node->next = NULL;
		free(crnt_node);
	}

	printf("I'm pop on line %u\n", ln);
}
