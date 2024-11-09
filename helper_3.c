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
		int exit_status = _atoi(status);
		if (exit_status < 0)
			return (-1);
		return (exit_status);
	}
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
	
	if (env == NULL)
		return;

	while ((env_var = env[i]) != NULL)
	{
		write(STDOUT_FILENO, env_var, _strlen(env_var));
		write(STDOUT_FILENO, "\n", 1);
		i++;
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
	if (av)
	{
		write(STDOUT_FILENO, av, _strlen(av));
		write(STDERR_FILENO, ": ", 2);
	}
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

	if (arr == NULL)
		return;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
