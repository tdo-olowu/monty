#include "monty.h"

#define RUN 0
#define STOP 1
#define BLANK " "
#define WIN 0

line_number = 0;

/**
 * read_from_file - read the monty file line by line.
 * this will populate the stack as program runs, dep on command received.
 * @filename: the path of the file.
 * @instr_stack: the stack to hold them instructions
 * Return: nothing. will exit with proper status.
 */
void read_from_file(char *filename, stack_t *instr_stack)
{
	int eval = RUN, exit_stat = -1;
	int argc = 0;
	size_t line_length = 0;
	ssize_t bytes_read = -1;
	char *line = NULL, **argv = NULL;
	void (*run_instr)(stack_t **, unsigned int);

	char *opcode;

	do {
		bytes_read = read_line(line, line_length, stdin);
		if (bytes_read < 0)
		{
			if (feof(stdin))
				exit_stat = WIN;
			else
				exit_stat = -1;
			eval = STOP;
		}
		else
		{
			line_number += 1;
			argv = make_tokens(line, BLANK);
			if (argv == NULL)
				continue;
			if (count_args(argv) > 0)
			{
				run_instr = get_instruction(argv[0]);
				run_instr(master_stack, line_num);
			}
		}
		free_table(argv);
	} while (eval == RUN);

	cleanup(line, argv);

	if (exit_stat == WIN)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
