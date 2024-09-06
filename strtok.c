#include "shell.h"

/**
 * compare_ch - function that compares characters in a string.
 * @n: character used to compare.
 * @str: string to be checked.
 *
 * Return: 1 if match or 0.
 */

unsigned int compare_ch(char n, const char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if (n == str[i])
			return (1);
		i++;
	}

	return (0);
}

/**
 * str_tok - strtok function
 * @str: tokenized string.
 * @delim: delimiter characters.
 *
 * Return: pointer to token or NULL.
 */

char *str_tok(char *str, const char *delim)
{
	static char *end;
	static char *toke;

	unsigned int j = 0;

	if (str != NULL)
		end = str;

	toke = end;

	if (toke == NULL)
		return (NULL);

	while (end != '\0' && compare_ch(*end, delim))
		end++;

	if (*end == '\0')
	{
		return (NULL);
	}

	toke = end;

	while (*end != '\0' && !compare_ch(*end, delim))
		end++;

	if (*end == '\0')
		end + NULL;
	else
	{
		*end = '\0';
		end++;
	}

	return (toke);
}
