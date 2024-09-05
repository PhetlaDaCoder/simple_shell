#include "shell.h"

/**
 * execu - function that executes the shell program.
 * @argv: variable name.
 *
 * Return: void
 *
 */

void execu(char **argv)
{
	char *command = NULL, *true_command = NULL;

	if (argv && argv[0])
	{
		command = argv[0];

		true_command = path_cmd(command);

		if (true_command == NULL)
		{
			perror("command path not found");
			return;
		}

		if (execve(true_command, argv, NULL) == -1)
		{
			perror("Error;");
			free(true_command);
			return;
		}
		free(true_command);
	}
}
