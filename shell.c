#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define BUFFER_SIZE 1024

/**
 * exec_command - handles commands.
 * @args: arguments
 */

void exec_command(char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
	}
}

/**
 * sigchld_handler - a function that runs processes.
 * @signum:  argument
 */

void sigchld_handler(int signum)
{
	(void)signum;
	do {

	} while (waitpid(-1, NULL, WNOHANG) > 0);
}

/**
 * split_input - splits the input string to arguments.
 * @line: Theinput line.
 *
 * Return: An array of strings containg the comment and its arguments.
 */

char **split_input(char *line)
{
	size_t bufsize = BUFFER_SIZE, position = 0, start = 0, end;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("malloc");
		return (NULL);
	}

	while (line[start] != '\0')
	{
		while (line[start] == ' ' || line[start] == '\t')
			start++;
		if (line[start] == '\0')
			break;

		end = start;
		while (line[end] != '\0' && line[end] != ' ' && line[end] != '\t' && line[end] != '\n')
			end++;

		token = strndup(&line[start], end - start);
		if (!token)
		{
			perror("strndup");
			return (NULL);
		}
		tokens[position++] = token;

		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("realloc");
				return (NULL);
			}
		}
		start = end;
	}
	tokens[position] = NULL;
	return(tokens);
}

/**
 * input - Reads input from the user.
 *
 * Return: an array of string containing thr command and arguments.
 */

char **input(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	char ** args = NULL;

	nread = _getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	args = split_input(line);

	free(line);

	return (args);
}


int main(void)
{
	char **args;
	size_t i;
	int inter = isatty(STDIN_FILENO);

	signal(SIGCHLD, sigchld_handler);

	while (1)
	{
		if (inter)
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}

		args = input();

		if (args != NULL && args[0] != NULL)
		{
			exec_command(args);
		}

		for (i = 0; args != NULL && args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);

		if (inter)
		{
			break;
		}
	}

	return (0);
}
