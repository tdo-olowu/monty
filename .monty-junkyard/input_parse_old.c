#include "monty.h"


/**
 * read_line - read opcodes
 * @buf: pointer to the input buffer
 * @lenptr: pointer to length of buffer
 * @filestr: filestream pointer.
 * Return: number of bytes read.
 */
ssize_t read_line(char **buf, size_t *lenptr, FILE *filestr)
{
	int i;
	char blank = ' ';
	ssize_t bytes_read;

	bytes_read = getline(buf, lenptr, filestr);
	if (bytes_read >= 0)
	{
		for (i = 0 ; (*buf)[i] == blank ; ++i)
			;
		for (; (*buf)[i] != '\n' ; ++i)
		{
			/* read opcode and arg */
		}
		(*buf)[i] = '\0';
		bytes_read -= 1;
	}

	return (bytes_read);
}


/**
 * make_tokens - tokenise a null-terminated string.
 * @str: the string to tokenise
 * @delim: the delimiter.
 * Return: array of strings i.e. the tokens.
 */
char **make_tokens(char *str, char *delim)
{
	int i, buf = 64, bufsize = 64;
	char *temp, **tokens;

	if (str == NULL)
		return (NULL);
	tokens = malloc(buf * sizeof(char **));
	if (tokens == NULL)
		return (NULL);

	temp = strtok(str, delim);
	for (i = 0 ; temp != NULL ; ++i)
	{
		if (i >= bufsize)
		{
			bufsize += buf;
			tokens = realloc(tokens, bufsize * sizeof(char **));
			if (tokens == NULL)
			{
				free_table(tokens);
				return (NULL);
			}
		}
		tokens[i] = strdup(temp);
		if (tokens[i] == NULL)
		{
			perror("couldn't parse all input.");
			free_table(tokens);
			return (NULL);
		}
		temp = strtok(NULL, delim);
	}
	tokens[i] = NULL;

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
 * convert_to_int - convert a string to integer
 * @n: integer as string
 * Return: -1 if n is not proper integer.
 */
int convert_to_int(char *n)
{
	long int value, failure = -1;
	const char *str = (const char *)n;
	char *endp;

	value = strtol(str, &endp, 10);
	if (*endp != '\0')
		return (failure);

	return ((int)value);
}
