#include "monty.h"

/**
 * main - main control for the monty
 * @argc: the argument count
 * @argv: list of arguments. should be opcodes
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	int success;
	char *filename;

	if (argc != 2)
	{
		fprintf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	/* try F_OK or R_OK || W_OK || X_OK if checks are failin */
	if (access(filename, R_OK) < 0)
	{
		fprintf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	success = read_from_file(filename);
	if (success < 0)
		exit(EXIT_FAILURE);

	return (success);
}
