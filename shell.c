#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_ARGUMENTS 10

/**
 * str_tok - function that copies a string.
 * @desti: pointer destination.
 * @source: source pointer.
 *
 * Return: Null.
 */

char *str_tok(char *desti, const char *source)
{
	char *point = desti;

	if (desti == NULL || source == NULL)
		return (NULL);
	while ((*desti++ = *source++))
		;
	return (point);
}

/**
 * get_line - reads a line from stdin or obj.
 * @line: pointer to charecter.
 * @p: pointter to length of line.
 * @obj: pointer o object.
 *
 * Return: totals chars.
 */

ssize_t get_line(char **line, size_t *size, FILE *stream)
{
	size_t buff = 0;
	ssize_t read = 0;
	int a;

	if (line == NULL)
		return (-1);

	if (*line == NULL || *size == 0)
	{
		buff = BUFFER_SIZE;
		*line = malloc(buff);

		if (*line == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		*size = buff;
	}

	while ((a = fgetc(stream)) != EOF)
	{
		(*line)[read++] = (char)a;

		if (read == (ssize_t)(*size - 1))
		{
			char *tmp = realloc(*line, buff + BUFFER_SIZE);

			if (tmp == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}

			*line = tmp;
			*size += BUFFER_SIZE;
		}

		if (a == '\n')
			break;
	}

	if (read == 0 && a == EOF)
		return (-1);
				
	(*line)[read] = '\0';
	return (read);
}

/**
 * prompt - prompts user for input.
 */

void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * **parse_input - parses input
 * @input: user input
 * @count: total arguments
 *
 * Return: argumensts.
 */

char **parse_input(char *input, size_t *count)
{
	char **arg = NULL;

	char *toke = strtok(input, " \n");

	while (toke != NULL)
	{
		arg = realloc(arg, (*count + 1) * sizeof(char *));
		arg[*count] = strdup(toke);
		(*count)++;

		toke = strtok(NULL, " \n");
	}

	arg = realloc(arg, (*count + 1) * sizeof(char *));
	arg[*count] = NULL;

	return (arg);
}

/**
 * input - reads user input
 *
 * Return: Arguments
 */
char **input(void)
{
	ssize_t back;
	size_t arg_count = 0, len = 0;
	char *u_input = NULL, **args = NULL;

	back = get_line(&u_input, &len, stdin);

	if (back == -1)
	{
		free(u_input);
		exit(EXIT_FAILURE);
	}
	else if (back == 0)
	{
		free(u_input);
		exit(EXIT_SUCCESS);
	}

	args = parse_input(u_input, &arg_count);

	free(u_input);

	return (args);

}
