#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
 * parse_input - Tokenizes the input line
 * @line: Input line to be parsed.
 * @args: Arguments array
 */

void parse_input(char *line, char *args[])
{
	int x = 0;

	args[x] = strtok(line, " ");
	while (args[x] != NULL && x < MAX_ARGS - 1)
	{
		x++;
		args[x] = strtok(NULL, " ");
	}
	args[x] = NULL;
}

/**
 * exe_command - Forks a process and executess the command.
 * @args: Array of arguments
 *
 */

void exe_command(char *args[])
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("Fork Error");
		return;
	}

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error Executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * interpreter - Prompts a user to enter a command with arguments
 * Return: 0 when done
 */

int interpreter(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t reader;
	char *args[MAX_ARGS];

	while (1)
	{
		write(STDOUT_FILENO, " # ", 3);

		reader = getline(&line, &length, stdin);
		if (reader == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (line[reader - 1] == '\n')
			line[reader - 1] = '\0';

		parse_input(line, args);
		if (args[0] != NULL)
		{
			exe_command(args);
		}
	}

	free(line);
	return (0);
}
