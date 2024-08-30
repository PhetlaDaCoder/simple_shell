#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>



/**
 * str_tok - function that copies a string.
 * @desti: pointer destination.
 * @source: source pointer.
 *
 * Return: Null.
 */

char *str_tok(char *desti, const char *source)
{
	char *point = desti;

	if (desti == NULL || source == NULL)
		return (NULL);
	while ((*desti++ = *source++))
		;
	return (point);
}

/**
 * parse_input - parses input.
 * @input: user input
 * @count: total arguments.
 *
 * Return: argumensts.
 */

char **parse_input(char *input, size_t *count)
{
	char **arg = NULL;
	char *toke;

	toke = str_tok(input, " \n");

	while (toke != NULL)
	{
		arg = realloc(arg, (*count + 1) * sizeof(char *));
		arg[*count] = strdup(toke);
		(*count)++;

		toke = str_tok(NULL, " \n");
	}

	arg = realloc(arg, (*count + 1) * sizeof(char *));
	arg[*count] = NULL;

	return (arg);
}

/**
 * input - reads user input
 *
 * Return: Arguments
 */
char **input(void)
{
	ssize_t back;
	size_t arg_count = 0, len = 0;
	char *u_input = NULL, **args = NULL;

	back = _getline(&u_input, &len, stdin);

	if (back == -1)
	{
		free(u_input);
		exit(EXIT_FAILURE);
	}
	else if (back == 0)
	{
		free(u_input);
		exit(EXIT_SUCCESS);
	}

	args = parse_input(u_input, &arg_count);

	free(u_input);

	return (args);

}

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
 * sigchld_handler - a function that runs a processes.
 * @signum: pointer to signal
 */

void sigchld_handler(int signum)
{
	(void)signum;

	do {

	} while (waitpid(-1, NULL, WNOHANG) > 0);

}

