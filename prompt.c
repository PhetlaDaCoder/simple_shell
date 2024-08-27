#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
 * interpreter - prompts a user to enter a command.
 * @x: pointer to arguments
 * @y: pointer to enviroment variable
 * Return: 0 when done.
 */

void interpreter(char **x char **y)
{
	char *str = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t ch_pid;
	int status;

	while (1)
	{
		printf("$ ");

		read = getline(&str, &len, stdin);
		if (read == -1)
		{
			perror("getline");
			free(str);
			exit(EXIT_FAILURE);
		}

		if (str[read - 1] == '\n')
		{
			str[read - 1] = '\0';
		}

		ch_pid = fork();
		if (ch_pid == -1)
		{
			perror("fork errro");
			free(str);
			exit(EXIT_FAILURE);
		}

		if (ch_pid == 0)
		{

			char *argv[] = {str, NULL};
			execve(argv[0], argv, y);

			perror("execve");
			exit(EXIT_FAILURE);
		}

		waitpid(ch_pid, &status, 0);
	}

	free(str);
}
