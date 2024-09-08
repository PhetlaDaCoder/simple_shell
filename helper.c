#include "shell.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 100

/**
 * handle_command - a function that handles command.
 * @line: pointer to given arguments.
 *
 * Return: NULL.
 */

void handle_command(char *line)
{
	char **argv = tokenize(line);

	if (argv[0] == NULL)
	{
		free(argv);
		return;
	}

	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
		free(argv);
		return;
	}

	execute_command(argv);
	free(argv);
}

/**
 * tokenize - a function that handles tokenization.
 * @line: pointer to argument.
 *
 * Return: return arguments or NULL.
 */

char **tokenize(char *line)
{
	char **argv = malloc(MAX_ARGS * sizeof(char *));
	char *token;
	int j = 0;

	token = str_tok(line, " \t\n");
	while (token != NULL && j < MAX_ARGS - 1)
	{
		argv[j] = token;
		token = str_tok(NULL, " \t\n");
		j++;
	}
	argv[j] = NULL;

	return (argv);
}

/**
 * print_env - prints the enviroment
 */

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * execute_command - a function that executes commands.
 * @argv: pointer to given arguments.
 *
 */

void execute_command(char **argv)
{
	pid_t pid;
	int status;

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

