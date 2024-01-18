#include "monty.h"


/**
 * push - pushes an element to the stack
    Usage: push <int>
        where <int> is an integer
    if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
        where is the line number in the file
    You won’t have to deal with overflows. Use the atoi function
 * @n: the int to push to the stack
 * Return: status
 *
 * push_instr - pushes an element to the stack
 * @stack: the stack
 * @ln: the line number
 * Return: none.
 */
void push_instr(stack_t **stack, unsigned int ln)
{
	printf("I'm push_instr on line %u\n", ln);
}


/**
 * pall - prints all the values on the stakc, starting from the top.
 * usage: pall
 * if the stack is empty, don't print anything
 * Format: print one per line.
 * @stack: the address of the stack.
 * Return: non.
 */
void pall_instr(stack_t **stack, unsigned int ln)
{
	printf("I'm pall on line %u\n", ln);
}


/**
 * pint - print the int at top of stack, followed by newline
 * Usage as opcode: pint (0-ary) if stack is empty, print the error msg
 * "L<line_num>: can't pint, stack empty, followed by a newline and exit with EXIT_FAILURE"
 * @stack: address of stack
 * Return: nunn
 */
void pint_instr(stack_t **stack, unsigned int ln)
{
	printf("I'm pint on line %u\n", ln);
}


/**
 * pop - remove and return top item from a stack.
 * Usage: pop.
 * if stack is empty, print the error message
 * "L<line_no>: can't pop an empty stack", then newline then EXIT_FAILURE
 */
int pop_instr(stack_t **stack, unsigned int ln)
{
	printf("I'm pop on line %u\n", ln);
}



/**
 * swap - swap the top two elements of the stack.
 * Usage: 0-ary. just type swap. if stack contains less than two elements, then error handle
 * "L<line_no>: can't swap, stack too short" then newline then EXIT_FAILURE
 * Return: none.
 */
void swap_instr(stack_t **stack, unsigned int ln)
{
	printf("I'm swap on line %u\n", ln);
}


/**
 * add - adds the top two elements of a stack.
 * usage: 0-ary add. takes no args.
 * store result in the second top element of stack, and top is removed. oh...so like a "reduce" 
 * towards the base of the stack. [x, x, ...] becomes [x+x, ...]
 * stack is one element shorter.
 * if stack has fewer than two elements, err handle
 * "L<line>: can't add, stack too short" then newline then EXIT_FAILURE
 * Return: no idea.
 */
void add_instr(stack_t **stack, unsigned int ln)
{
	printf("I'm add on line %u\n", ln);
}


/**
 * nop - does nothing.
 * @stack: plates.
 * Return: nay
 */
void nop_instr(stack_t **stack, unsigned int ln)
{
	printf("I'm nop on line %u and I do nothing.\n", ln);
}
