#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMM 10


/**
 * interpreter - prompts a user to enter a command.
 *
 * @x: pointer to arguments.
 *
 * @env: pointer to enviroment variable.
 *
 * Return: void
 */

void interpreter(char **x, char **env)
{
	char *str = NULL;
	size_t b = 0;
	char *argv[MAX_COMM];
	ssize_t num;

	while (1)
	{
		num = user_input(&str, &b);
		if (num == -1)
		{
			perror("getline");
			free(str);
			exit(EXIT_FAILURE);
		}

		if (str[num - 1] == '\n')
		{
			str[num - 1] = '\0';

		}

		par_command(str, argv);

		if (argv[0] != NULL)
		{
			execute_command(argv, env, x);
		}
	}
	free(str);
}


/**
 * user_input - displays prompt and reads input.
 * @str: pointer to input string.
 * @b: pointer to buffer size.
 *
 * Return: toal bytes or -1 if failed.
 */
ssize_t user_input(char **str, size_t *b)
{
	printf("$ ");
	return (getline(str, b, stdin));
}

/**
 * execute_command - forks process and executes command.
 * @argv: arguments array.
 * @env: enviroment variable.
 * @x: array of arguments for error.
 */

void execute_command(char **argv, char **env, char **x)
{
	char *path = path_command(argv[0], env, x);

	pid_t ch_pid;
	int status;

	if (path == NULL)
	{
		fprintf(stderr, "%s; command not found\n", argv[0]);
		return;
	}

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (ch_pid == 0)
	{
		argv[0] = path;
		exec_command(argv, env, x);
	}
	else
	{
		waitpid(ch_pid, &status, 0);
		free(path);
	}
}

/**
 * par_command - splits input string to arguments.
 *
 * @str: first string.
 *
 * @argv: second string.
 */

void par_command(char *str, char *argv[])
{
	int c = 0;

	c = 0;

	argv[c] = strtok(str, " ");
	while (argv[c] != NULL && c < MAX_COMM - 1)
	{
		c++;
		argv[c] = strtok(NULL, " ");
	}
	argv[c] = NULL;
}

/**
 * exec_command - handles execve call and error handling.
 * @argv: first argument.
 *
 * @env:enviroment variable.
 *
 * @x: second argument.
I */

void exec_command(char **argv, char **env, char **x)
{
	if (execve(argv[0], argv, env) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
