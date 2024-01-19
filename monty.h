#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


extern unsigned int line_num;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;


/* FILE HANDLING */
void read_from_file(char *, stack_t *, FILE *);


/* LINE PARSING */
char **make_tokens(char *, char *);
int count_args(char **);
ssize_t readline(char *, size_t *, FILE *);
int convert_to_int(char *);
int get_arg(unsigned int);


/* STACK HANDLING */
stack_t *new_stack(void);
void free_stack(stack_t *);


/* INSTRUCTIONS */
void (*get_instruction(char *))(stack_t *, unsigned int);
void push_instr(stack_t *, unsigned int);
void pall_instr(stack_t *, unsigned int);
void pint_instr(stack_t *, unsigned int);
void pop_instr(stack_t *, unsigned int);
void swap_instr(stack_t *, unsigned int);
void add_instr(stack_t *, unsigned int);


/* MEMORY MANAGEMENT */
void free_table(char **);
void cleanup(char *, char **);



#endif /* MONTY_H */
