#include "monty.h"

/**
 * main - main control for the monty
 * @argc: the argument count
 * @argv: list of arguments. should be opcodes
 * Return: 0 for success.
 */
int main(int argc, char **argv)
{
	char *filename;
	FILE *file;
	stack_t *instruction_stack = new_stack();

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	/* try F_OK or R_OK || W_OK || X_OK if checks are failin */
	if (access(filename, R_OK) < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	read_from_file(filename, instruction_stack, file);

	fclose(file);
	free_stack(instruction_stack);

	return (0);
}
