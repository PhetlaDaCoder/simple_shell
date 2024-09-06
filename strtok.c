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

	while (str[j] != '\0')
	{
		if (n == *str)
			return (1);
		i++;
	}

	return (0);
}

/**
 * str_tok - strtok function
 * @str: tokenized string.
 * @deli,: delimiter characters.
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

	while (end[j] != '\0')
	{
		if (compare_ch(end[j]. delim) == 0)
			break;
		j++;
	}

	if (*end == '\0' || *end == '#')
	{
		*end = '\0';
		return (NULL);
	}

	toke = end + j;
	end = toke;

	j = 0;

	while (end[j] != '\0')
	{
		if (compare_ch(end[j], delim) == 1)
			break;
		j++;
	}

	if (end[j] == '\0')
		end = NULL;
	else
	{
		end[j] = '\0';
		end = end + j + 1;
		if (*end == '\0')
			end = NULL;
	}
	return (toke);
}
