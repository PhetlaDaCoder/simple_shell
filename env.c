#include "shell.h"

/**
 * print_env - prints enviroment variables
 *
 * Return: o when done or - 1 if error.
 */

int print_env(void)
{
	char **env_point = environ;

	while (*env_point)
	{

		size_t len = 0;

		while ((*env_point)[len])
			len++;

		write(STDOUT_FILENO, *env_point, len);
		write(STDOUT_FILENO, "\n", 1);

		env_point++;
	}

	return (0);
}
