#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * interpreter - prompts a user to enter a command with arguments and executes
 * Return: 0 when done
 */

int interpreter(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t reader;
	char *args[8];
	int x;
	pid_t pid;
	int status;

	while (1)
	{
		while(STDOUT_FILENO, " # ", 3);

		reader = getline(&line, &length, stdin);
		if (reader == -1)
		{
			write(STDOUT_FILENO, "\n");
			break;
		}

		x = 0;
		args[x] = strtok(line,"\n");
		if (args[x] == NULL)
		{
			continue;
		}
		while (args[x] != NULL && x < 7)
		{
			x++;
			args[x] = strtok(NULL, "\n");
		}
		args[x] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("Fork Error");
			continue;
		}

		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
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

	free(line);
	return (0);
}

