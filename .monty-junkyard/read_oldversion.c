#include "monty.h"

/**
 * read_from_file - read the monty file line by line.
 * PROTOCOL while there's a line, read the line,
 * parse it i.e. extract opcode and first n args, call appropriate function by name,
 * then move to next line.
 * @filename: the path of the file.
 * Return: -1 if any error occured, 0 if no big deal.
 */
int read_from_file(char *filename)
{
	int argc = 0, status = -1;
	size_t line_length = 0;
	ssize_t bytes_read = -1;
	char *line = NULL, **argv = NULL;

	char *opcode;
	int oparg;
	unsigned int line_num;

	bytes_read = read_line(line, line_length, stdin);
	if (bytes_read >= 1)
	{
		argv = make_tokens(line);
		argc = count_args(argv);
		/* just pass the first cmd and the arg to the function finder */
		if (argc >= 2)
		{
			/* let function finder handle it, incl nop */
			opcode = argv[0];
			oparg = convert_to_int(argv[1]);
		}
		else if (argc == 1)
		{
			/* only reason for this is to avoid segfault */
			opcode = argv[0];
			/* call the function finder */
		}
	}

	return (status);
}

/**
{
do {
		bytes_read = getcmd(&cmdline, &cmdlen, stdin);
		if (bytes_read < 0)
		{
			if (feof(stdin))
			{
				exit_stat = 0;
				break;
			}
		}
		else
		{
			argv = make_tokens(cmdline, " ");
			if (argv == NULL)
				continue;
			exit_stat = is_exit(argv);
			if (exit_stat >= 0)
			{
				free_table(argv);
				break;
			}
			if (exit_stat == -10)
			{
				free_table(argv);
				eval = 1;
				continue;
			}
			eval = evaluate(argv, envp);
			free_table(argv);
		}
	} while (eval == 1);
	cleanup(cmdline, envp);
	exit(exit_stat);
}
**/
