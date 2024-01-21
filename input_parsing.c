#include "monty.h"


/**
 * make_tokens - tokenise a null-terminated string.
 * @str: the string to tokenise
 * @delim: the delimiter.
 * Return: array of strings aka the tokens.
 */
char **make_tokens(char *str, char *delim)
{
	int tok_count = 2;
	int i;
	char *temp = NULL, **tokens = NULL;

	printf("Inside make_tokens. string is **%s**\n", str);
	if (str == NULL)
		return (NULL);
	tokens = malloc((tok_count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		puts("Could not tokenise!\n");
		return (NULL);
	}

	temp = strtok(str, delim);
	for (i = 0; temp != NULL ; ++i)
	{
		/* don't ask for more memory */
		tokens[i] = strdup(temp);
		if (tokens[i] == NULL)
		{
			fprintf(stdout, "Could not tokenize ):\n");
			/* btw, why does free_table work here? */
			free_table(tokens);
			return (NULL);
		}
		temp = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	print_tokens(tokens); /* DEBUG */

	return (tokens);
}


/**
 * get_instruction - given the opcode, retrieve the instr
 * @cmd_name: the opcode, just its name.
 * Return: pointer to the function.
 */
void (*get_instruction(char *cmd_name))(stack_t **, unsigned int)
{
	int i, range;
	char *bin_name;
	void (*bin_instr)(stack_t **, unsigned int);
	instruction_t instr_map[] = {{"push", push_instr}, {"pall", pall_instr},
				     {"pint", pint_instr}, {"pop", pop_instr},
				     {"swap", swap_instr}, {"add", add_instr},
				     {"nop", nop_instr}};

	printf("Command name: %s\n", cmd_name); /* DEBUG */

	range = sizeof(instr_map) / sizeof(instruction_t);
	for (i = 0 ; i < range ; ++i)
	{
		bin_name = (instr_map[i]).opcode;
		bin_instr = (instr_map[i]).f;
		if (strcmp(cmd_name, bin_name) == 0)
			return (bin_instr);
	}

	return (NULL);
}



/**
 * count_args - count the number of arguments in an argv.
 * an improvement would be to return -1 if argv == NULL to
 * distinguish from when argv != NULL but its first arg is NULL.
 * @argv: list of string.
 * Return: number of arguments.
 */
size_t count_args(char **argv)
{
	int i;
	size_t count = 0;

	if (argv == NULL)
		count = 0;
	else
	{
		for (i = 0, count = 0 ; argv[i] != NULL ; ++i)
			++count;
	}

	return (count);
}



/**
 * read_line - read opcodes
 * @buf: pointer to the buffer i.e. memry where line is stored.
 * @lenptr: pointer to length of buffer
 * @filestr: filestream pointer.
 * Return: number of bytes read.
 */
ssize_t read_line(char **buf, size_t *lenptr, FILE *filestr)
{
	ssize_t bytes_read = -1;

	bytes_read = getline(buf, lenptr, filestr);

	return (bytes_read);
}
