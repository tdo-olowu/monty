#include "main.h"


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
