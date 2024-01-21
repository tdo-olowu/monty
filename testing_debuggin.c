#include "monty.h"

/**
 * print_tokens - print all the tokens obtained.
 * @toks: an array of strings
 * Return: none.
 */
void print_tokens(char **toks)
{
	int i;

	if (toks == NULL)
		puts("(nil)\n");
	else
	{
		for (i = 0 ; toks[i] != NULL ; ++i)
		{
			printf("%s\n", toks[i]);
		}
	}
}
