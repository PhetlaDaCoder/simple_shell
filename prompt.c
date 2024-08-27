#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
 * interpreter - prompts a user to enter a command.
 * @x: pointer to arguments
 * @env: pointer to enviroment variable
 * Return: 0 when done.
 */

void interpreter(char **x, char **env)
{
	char *str = NULL;
	int a, status;
	size_t b = 0;
	ssize_t num;
	char *argv[] = {NULL, NULL};
	pid_t ch_pid;

	while (1)
	{
		printf("$ ");
		num = getline(&str, &b, stdin);
		if (num == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		a = 0;
		while (str[a])
		{
			if (str[a] == '\n')
				str[a] = 0;
		}
		argv[0] = str;
		ch_pid = fork();
		if (ch_pid == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (ch_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", x[0]);
		}
		else
			wait(&status);
	}
}

