#include "shell.h"

/**
 * prompt - Displays a prompt and waits for user inout.
 * @input: string variable
 * @len: buffer size
 * Return: success , otherwise -1
 */

ssize_t prompt(char **input, size_t len)
{
	ssize_t nr;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
	if (input == NULL)
	{
		write(STDERR_FILENO, "Null input pointer\n", 19);
		return (-1);
	}

	nr = getline(input, &len, stdin);
	if (nr == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(*input);
		*input = NULL;
		exit(EXIT_FAILURE);
	}

	return (nr);
}
