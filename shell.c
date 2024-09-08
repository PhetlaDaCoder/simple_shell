#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARG 64

/**
 * prompt - function that prompts the user.
 */

void prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

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
 * handle_command - a function that handles commands.
 * @line: given argument.
 *
 * Return: NULL.
 */

void handle_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[MAX_ARG];
	char *token;
	char **env;
	int j = 0;

	token = str_tok(line, " \t\n");
	while (token != NULL && j < MAX_ARGS - 1)
	{
		argv[j] = token;
		token = str_tok(NULL, " \t\n");
		j++;
	}
	argv[j] = NULL;

	if (argv[0] == NULL)
		return;

	if (str_cmp(argv[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (str_cmp(argv[0], "env") == 0)
	{
		env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		return;
	}

	pid = fork();

	if (pid == -1)
	{
		perror("fork failure");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execvp(argv[0], argv);
		perror("Command execution failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid failure");
			exit(EXIT_FAILURE);
		}
	}
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
