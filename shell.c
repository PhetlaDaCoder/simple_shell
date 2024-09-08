#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARG 64

/**
 * parse_input - a function that parses user inpit.
 * @input: pointer to user input.
 * @arg_count: total arguments counted.
 *
 * Return: total arguments.
 */

char **parse_input(char *input, size_t *arg_count)
{
	char **args = NULL;
	char *token = strtok(input, " \n");

	while (token != NULL)
	{
		args = realloc(args, (*arg_count + 1) * sizeof(char *));
		if (args == NULL)
		{
			perror("Allocation error");
			exit(EXIT_FAILURE);
		}
		args[*arg_count] = strdup(token);

		if (args[*arg_count] == NULL)
		{
			perror("Duplication error");
			exit(EXIT_FAILURE);
		}


		(*arg_count)++;
		token = strtok(NULL, " \n");
	}

	args = realloc(args, (*arg_count + 1) * sizeof(char *));
	args[*arg_count] = NULL;

	return (args);
}

/**
 * get_input - reads a users input.
 *
 * Return: void.
 */

char **get_input(void)
{
	ssize_t response;
	size_t arg_count = 0, len = 0;
	char *input = NULL, **args = NULL;

	response = _getline(&input, &len, stdin);

	if (response == -1)
	{
		free(input);
		exit(EXIT_FAILURE);
	}
	else if (response == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}

	args = parse_input(input, &arg_count);
	free(input);

	return (args);
}
/**
 * main - main function of the program.
 *
 * Return: 0 when done.
 *
 */

int main(void)
{
	ssize_t char_read;
	char *line = NULL;
	size_t n = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();

		char_read = _getline(&line, &n, stdin);
		if (char_read == -1)
		{
			perror("error");
			free(line);
			exit(EXIT_FAILURE);
		}

		handle_command(line);
		free(line);
		line = NULL;
		n = 0;
	}

	return (0);
}
