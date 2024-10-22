#include "shell.h"

/**
 * not_issaty - Non-interactive mode of the shell.
 * @env: The enviroment variables
 *
 * Return: The exit status or success
 */

int not_issaty(char **env)
{
	char *input = NULL, **cmd;
	ssize_t nread;
	size_t len = 0;
	int exit_status = 0, execute;

	if (access("/dev/tty", F_OK) != 0)
	{
		write(STDERR_FILENO, "Error: Input is not interactive.\n", 34);
		return (1);
	}

	while ((nread = getline(&input, &len, stdin)) != -1)
	{
		cmd = token(input);
		if (nread == 0)
		{
			break;
		}
		else if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_status = exit_(cmd[1]);
			if (exit_status != -1)
			{
				free_cmd_arg(cmd);
				free(input);
				return (exit_status);
			}
		}
		else if (_strcmp(cmd[0], "env") == 0)
		{
			printenv(env);
		}
		else
		{
			execute = exec(cmd);
			if (execute != 0)
			{
				free_cmd_arg(cmd);
				continue;
			}
		}
		free_cmd_arg(cmd);
		free(input);
		input = NULL;
		len = 0;
	}
	return (exit_status);
}
