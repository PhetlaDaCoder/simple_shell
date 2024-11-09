#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * prompt - Displays a prompt and waits for user inout.
 * @input: string variable
 * @len: buffer size
 * Return: success , otherwise -1
 */

ssize_t prompt(char **input, size_t len)
{
	ssize_t nr;

	if (input == NULL || len == NULL)
	{
		write(STDERR_FILENO, "Null input pointer\n", 19);
		return (-1);
	}

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}

	nr = getline(input, len, stdin);
	if (nr == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(*input);
		*input = NULL;
		return (-1);
	}

	return (nr);
}
