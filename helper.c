#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * find_token - finds the next token.
 * @str_ptr: pointer to current string.
 * @delim: delimiters used
 *
 * Return: pointer or NULL if failed
 */

char *find_token(char **str_ptr, const char *delim)
{
	char *start;
	char *end;

	start = *str_ptr;

	if (start == NULL)
		return (NULL);

	while (*start && strchr(delim, *start))
		start++;

	if (*start == '\0')
		return (NULL);

	end = start;
	while (*end && !strchr(delim, *end))
		end++;

	if (*end)
	{
		*end = '\0';
		*str_ptr = end + 1;
	}
	else
	{
		*str_ptr = NULL;
	}

	return (start);
}

/**
 * store_argument - adds token to argument list;
 * @args: pointer ro argument count.
 * @count: pointer to argument count.
 * @token: tokento add.
 */
static void store_argument(char ***args, size_t *count, const char *token)
{
	*args = realloc(*args, (*count + 1) * sizeof(char *));
	if (*args == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}

	(*args)[*count] = strdup(token);
	if ((*args)[*count] == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	(*count)++;
}

/**
 * parse_input - parses user input into arguments.
 * @input: users input.
 * @count: pointer to the count of arguments.
 *
 * Return: array of arguments.
 */

char **parse_input(char *input, size_t *count)
{
	char **args = NULL;
	char *token;

	*count = 0;

	while ((token = find_token(&input, " \n")) != NULL)
	{
		store_argument(&args, count, token);
	}

	args = realloc(args, (*count + 1) * sizeof(char *));
	if (args == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	args[*count] = NULL;

	return (args);
}


