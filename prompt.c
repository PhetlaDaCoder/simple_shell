#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMM 10

/**
 * interpreter - prompts a user to enter a command.
 * @x: pointer to arguments
 * @env: pointer to enviroment variable
 * Return: 0 when done.
 */

void interpreter(char **x, char **env)
{
	char *str = NULL;
	size_t b = 0;
	ssize_t num;
	char *argv[MAX_COMM];
	pid_t ch_pid;
	int status;

	while (1)
	{
		printf("$ ");
		num = getline(&str, &b, stdin);
		if (num == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}

		str[strcspn(str, "\n")] = '\0';

		par_command(str, argv);

		ch_pid = fork();
		if (ch_pid == -1)
		{
			free(str);
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (ch_pid == 0)
		{
			exec_command(argv, env, x);
		}
		else
		{
			wait(&status);
		}
	}
	free(str);
}

/**
 * par_command - splits input string to arguments
 * @str: first string
 * @argv: second string
 */

void par_command(char *str, char *argv[])
{
	int c = 0;

	argv[c] = strtok(str, " ");
	while (argv[c] != NULL && c < MAX_COMM - 1)
	{
		c++;
		argv[c] = strtok(NULL, " ");
	}
	argv[c] = NULL;
}

/**
 * exec_command - handles execve call and error handling
 * @argv: first argument
 * @env:enviroment variable
 * @x: second argument
 */

void exec_command(char **argv, char **env, char **x)
{
	if (execve(argv[0], argv, env) == -1)
	{
		fprintf(stderr, "%s: No such file or directory\n", x[0]);
		exit(EXIT_FAILURE);
	}
}
