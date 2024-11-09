#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * main - main program
 * @ac: Items in av
 * @av: NULL array of strings
 * @env: Null array of strings
 *
 * Return: 0 or -1
 */

int main(int ac, char **av, char **env)
{
	char *input, **cmd;
	ssize_t nread;
	size_t len = 0;
	int exit_status, execute;

	(void) ac;
	(void) av;

	if (access("/dev/tty", F_OK) != 0)
	{
		return (not_issaty(env));
	}

	while (1)
	{
		nread = prompt(&input, &len);
		if (nread == -1)
		{
			free(input);
			break;
		}

		cmd = token(input);
		if (cmd == NULL)
		{
			free(input);
			continue;
		}

		if (_strcmp(cmd[0], "exit") == 0)
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
	}
	free(input);
	return (exit_status);
}
