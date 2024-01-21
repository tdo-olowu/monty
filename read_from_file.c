#include "monty.h"

#define BLANK " "
#define WIN 0
#define FAIL -1
#define UNKNOWN "L%u: unknown instruction %s\n"

char **line_tok = NULL;

/**
 * read_from_file - read the monty file line by line.
 * this will populate the stack as program runs, dep on command received.
 * if line is empty, continue.
 * @instr_stack: the stack to hold them instructions
 * @fobj: pointer to FILE object
 * Return: nothing. will exit with proper status.
 */
void read_from_file(stack_t *instr_stack, FILE *fobj)
{
	int exit_stat = FAIL;
	unsigned int line_num = 0;
	size_t line_length = 0;
	ssize_t bytes_read = -1;
	char *cr_line = NULL, *opcode = NULL;
	void (*run_instr)(stack_t **, unsigned int);

	do {
		/* read_line or getline? */
		bytes_read = read_line(&cr_line, &line_length, fobj);
		if (bytes_read < 0)
			break;
		++line_num;
		if (bytes_read == 0)
			continue;
		nlinestrip(&cr_line);
		/* printf("***\nline %u\n\t%s\n", line_num, cr_line); */
		line_tok = make_tokens(cr_line, BLANK);
		if (line_tok == NULL)
			continue;
		if (count_args(line_tok) > 0)
		{
			opcode = line_tok[0];
			run_instr = get_instruction(opcode);
			if (run_instr == NULL)
			{
				fprintf(stderr, UNKNOWN, line_num, opcode);
				exit_stat = FAIL;
				break;
			}
			else
				run_instr(&instr_stack, line_num);
		}
		/* should I free the line_tok after each ln? */
		/* or is it safe to overwrite same block of memry? */
		free_table(line_tok);
	} while (bytes_read >= 0);

	free(cr_line);
	if (bytes_read < 0)
		exit_stat = (feof(stdin) ? WIN : FAIL);
	if (exit_stat == FAIL)
		exit(EXIT_FAILURE);
}
