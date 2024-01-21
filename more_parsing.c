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
		fprintf(stdout, "Could not duplicate string\n");
		/* exit(EXIT_FAILURE); not sure we should exit */
		return (NULL);
	}
	strcpy(dest, src);

	return (dest);
}



/**
 * is_an_int - checks if str represents an integer.
 * this version is crude.
 * @str: the string to test.
 * Return: 1 if str is integer, 0 otherwise.
 */
int is_an_int(char *str)
{
	int i, yes = 1, nay = 0;
	char ch;

	if (str == NULL)
		return (nay);
	for (i = 0 ; str[i] != '\0' ; ++i)
	{
		ch = str[i];
		if ((ch < '0') || (ch > '9'))
			return (nay);
		else if ((ch == '-') && (i > 0))
			return (nay);
		else if ((ch == '+') && (i > 0))
			return (nay);
	}

	return (yes);
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
	(void)failure;

	value = strtol(str, &endp, 10);
	if (*endp != '\0')
	{
		fprintf(stdout, "Could not convert to integer\n");
		/* should we exit or return something? */
		exit(EXIT_FAILURE);
	}

	return ((int)value);
}



/**
 * nlinestrip - strip away the trailing newline.
 * it's been causing trouble for my dear code.
 * @line: line to trim.
 * Return: nothing. modify via pointer.
 */
void nlinestrip(char **line)
{
	int i;

	if ((line != NULL) && ((*line) != NULL))
	{
		for (i = 0 ; (*line)[i] != '\0' ; ++i)
		{
			if ((*line)[i] == '\n')
			{
				(*line)[i] = '\0';
				break;
			}
		}
	}
}
