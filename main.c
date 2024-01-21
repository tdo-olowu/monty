#include "monty.h"


/**
 * main - main control for the monty
 * try F_OK or R_OK || W_OK || X_OK if checks are failin
 * @argc: the argument count
 * @argv: list of arguments. should be opcodes
 * Return: 0 for success.
 */
int main(int argc, char **argv)
{
	char *filename;
	FILE *file;
	stack_t *instruction_stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
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
	instruction_stack = malloc(sizeof(stack_t));
	if (instruction_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	stack_memset(instruction_stack);
	read_from_file(instruction_stack, file);

	fclose(file);
	free_stack(instruction_stack);

	return (0);
}
