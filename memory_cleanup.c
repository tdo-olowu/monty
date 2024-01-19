#include "main.h"


/**
 * free_table - frees a null-terminated array of strings
 * check if *table is NULL
 * @table: an array of strings.
 * Return: none.
 */
void free_table(char **table)
{
	int i;

	if (table != NULL)
	{
		for (i = 0 ; table[i] != NULL ; ++i)
			free(table[i]);
	}
	free(table);
}


/**
 * free_list - free the list
 * @stack: the stack to be freed.
 * Return: no return, just free memory occupied by the linkedlist.
 */
void free_list(stack_t *stack);



/**
 * cleanup - a function for convenience.
 * @line: a string.
 * @table: an array of strings.
 * Return: none.
 */
void cleanup(char *line, char **table)
{
	if (line != NULL)
	{
		free(line);
	}
	if (table != NULL)
		free_table(table);
}
