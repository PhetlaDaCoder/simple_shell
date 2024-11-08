#include "shell.h"

/**
 * exit_ - Ends a calling processs.
 * @status: Exit status
 *
 * Return: Exits status or -1
 */

int exit_(char *status)
{
	if (status == NULL || *status == '\0')
	{
		return (0);
	}
	else
	{
		return (_atoi(status));
	}
	return (-1);
}

/**
 * printenv - Prints enviroment
 * @env: enviroment variables
 *
 */

void printenv(char **env)
{
	int i = 0;
	char *env_var;

	env_var = env[i];
	while (env_var != NULL)
	{
		write(STDOUT_FILENO, env_var, _strlen(env_var));
		write(STDOUT_FILENO, "\n", 1);
		i++;
		env_var = env[i];
	}
}

/**
 * error - prints errors
 * @message: error message.
 * @av: command nane.
 *
 */
void error(const char *message, char *av)
{
	write(STDERR_FILENO, av, _strlen(av));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * free_cmd_arg - frees array of memmory
 * @arr: Array of words
 *
 */

void free_cmd_arg(char **arr)
{
	int i;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
