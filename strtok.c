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
 * @t: character to validate.
 * @string: string to find.
 *
 * Return: 1 if true or 0 if false.
 */

unsigned int vali_char(char t, const char *string)
{
	unsigned int i = 0;

	while (string[i] != '\0')
	{
		if (t == *string)
			return (1);
		i++;
	}

	return (0);
}

/**
 * str_tok - custom strtok func.
 * @st: string to be tokenized
 * @dlim: delimeter chars.
 *
 * Return: pointer to token or NULL.
 */

char *str_tok(char *st, const char *dlim);
char *str_tok(char *st, const char *dlim)
{
	static char *las;
	static char *tok;
	unsigned int j = 0;

	if (st != NULL)
		las = st;

	tok = las;

	if (tok == NULL)
		return (NULL);
	while (last[j] != '\0')
	{
		if (vali_char(las[j], dlim) == 0)
			break;
		j++;
	}

	if (*las == '\0' || *las == '#')
	{
		*las = '\0';
		return (NULL);
	}

	tok = las + j;
	las = token;

	j = 0;

	while (las[j] != '\0')
	{
		if (vali_vahr(las[j], dlim) == 1)
			break;
		j++;
	}

	if (las[j] == '\0';
		last = NULL;

	else
	{
		las[j] = '\0';
		las = las + j + 1;
		if (*las == '\0')
			las = NULL;
	}
	return (tok);
}

