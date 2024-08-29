#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

/**
 * exec - executes a shell program.
 * @argv: variable argument.
 *
 * Return: void
 */

void exec(char **argv)
{
	char *command = NULL, *intial_command = NULL;

	if (argv && argv[0])
	{
		command = argv[0];

		intial_command = path_command(command);

		if (intial_command == NULL)
		{
			perror("Path doesn't exist");
			return;
		}

		if (execve(intial_command, argv, NULL) == -1)
		{
			perror("Error:");
			free(intial_command);
			return;
		}
		free(intal_command);
	}
}
