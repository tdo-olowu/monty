#include "monty.h"

#define RUN 0
#define STOP 1
#define BLANK " "
#define WIN 0
#define FAIL -1
#define UNKNOWN "L%u: unknown instruction %s\n"

line_num = 0;

/**
 * read_from_file - read the monty file line by line.
 * this will populate the stack as program runs, dep on command received.
 * @filename: the path of the file.
 * @instr_stack: the stack to hold them instructions
 * @fobj: pointer to FILE object
 * Return: nothing. will exit with proper status.
 */
void read_from_file(char *filename, stack_t *instr_stack, FILE *fobj)
{
	int eval = RUN, exit_stat = FAIL, argc = 0;
	size_t line_length = 0;
	ssize_t bytes_read = -1;
	char *line = NULL, **argv = NULL;
	void (*run_instr)(stack_t **, unsigned int);

	do {
		bytes_read = getline(&line, &line_length, fobj);
		if (bytes_read < 0)
		{
			if (feof(stdin))
				exit_stat = WIN;
			else
				exit_stat = FAIL;
			break;
		}
		line_num += 1;
		argv = make_tokens(line, BLANK);
		if (argv == NULL)
			continue;
		if (count_args(argv) > 0)
		{
			run_instr = get_instruction(argv[0]);
			if (run_instr == NULL)
			{
				fprintf(stderr, UNKNOWN, line_num, argv[0]);
				exit_stat = FAIL;
				eval = STOP;
			}
			else
				run_instr(instr_stack, line_num);
		}
		free_table(argv);
	} while (eval == RUN);
	cleanup(line, argv);

	if (exit_stat == FAIL)
		exit(EXIT_FAILURE);
}
