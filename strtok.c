#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>

/**
 * vali_char - a function that validates charecters in a string.
 * @ch: character to validate.
 * @str: string to find.
 *
 * Return: 1 if true or 0 if false.
 */

unsigned int vali_char(char ch, const char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if (ch == *str)
			return (1);
		i++;
	}

	return (0);
}

/**
 * str_to - custom strtok func.
 * @str: string to be tokenized
 * @delim: delimeter chars.
 *
 * Return: pointer to token or NULL.
 */

char *str_to(char *str, const char *delim);
char *str_to(char *str, const char *delim)
{
	static char *las;
	static char *tok;
	unsigned int j = 0;

	if (str != NULL)
		las = str;

	tok = las;

	if (tok == NULL)
		return (NULL);
	while (las[j] != '\0')
	{
		if (vali_char(las[j], delim) == 0)
			break;
		j++;
	}

	if (*las == '\0' || *las == '#')
	{
		*las = '\0';
		return (NULL);
	}

	tok = las + j;
	las = tok;

	j = 0;

	while (las[j] != '\0')
	{
		if (vali_char(las[j], delim) == 1)
			break;
		j++;
	}

	if (las [j] == '\0')
		las = NULL;
	else
	{
		las [j] = '\0';
		las = las +j + 1;
		if (*las == '\0')
			las = NULL;
	}
	return (tok);
}

