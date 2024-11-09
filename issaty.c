#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * not_issaty - Non - interactive mode of the shell/
 * @env: Enviroment variable
 *
 * Return: Exit status or success.
 */

int not_issaty(char **env)
{
	char *input = NULL;
	char **cmd = token(input);
	ssize_t nread;
	size_t len = 0;
	int exit_status = 0;

	if (access("/dev/tty", F_OK) != 0)
	{
		write(STDERR_FILENO, "Error: Input is not interactive.\n", 34);
		return (1);
	}

	while ((nread = getline(&input, &len, stdin)) != -1)
	{
		cmd = token(input);

		exit_status = handle_command(cmd, env, &exit_status);

		free_cmd_arg(cmd);

		input = NULL;
		len = 0;
	}

	free(input);
	return (exit_status);
}

/**
 * handle_command - Executes a commmand.
 * @cmd: Command to be executed
 * @env: The enviroment variables
 * @exit_status: Pointer to exit status.
 *
 * Return: 0 when done or NULL on failure.
 */

int handle_command(char **cmd, char **env, int *exit_status)
{
	if (_strcmp(cmd[0], "exit") == 0)
	{
		*exit_status = exit_(cmd[1]);
		return (1);
	}
	else if (_strcmp(cmd[0], "env") == 0)
	{
		printenv(env);
	}
	else
	{
		return (exec(cmd));
	}
	return (0);
}

/**
 * cleanup - A function that cleans memory
 * @cmd: First argument
 * @input: Second argument
 */

void cleanup(char **cmd, char *input)
{
	free_cmd_arg(cmd);
	free(input);
}
