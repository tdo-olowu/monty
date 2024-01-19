#include "monty.h"


/**
 * _strdup - an implementation of strdup
 * @src: the string to copy.
 * Return: copy of the string.
 */
char *_strdup(const char *src)
{
	int lngth;
	char *dest;

	if (src == NULL)
		return (NULL);
	lngth = strlen(src) + 1;
	dest = malloc(lngth * sizeof(char));
	if (dest == NULL)
	{
		perror("Could not duplicate string");
		exit(EXIT_FAILURE);
	}
	strcpy(dest, src);

	return (dest);
}
