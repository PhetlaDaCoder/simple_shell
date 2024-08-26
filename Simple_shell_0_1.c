#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * interpreter - prompts a user to enter a command.
 * Return: 0 when done.
 */

int interpreter(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t reader;
	char *args[8];
	int x;

	while (1)
	{
		write(STDOUT_FILENO, " # ", 3);

		reader = getline(&line, &length, stdin);
		if (reader == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		x = 0;
		args[x] = strtok(line, "\n");
		while (args[x] != NULL && x < 7)
		{
			x++;
			args[x] = strtok(NULL, " \n");
		}
		args[x] = NULL;

		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error invalid command");
		}
	}

	free(line);
	return (0);
}
