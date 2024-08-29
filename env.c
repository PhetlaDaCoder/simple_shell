#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

/**
 * print_env - prints enviroment variable.
 * Return: o when done.
 *
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
