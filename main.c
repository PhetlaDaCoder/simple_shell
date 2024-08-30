#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - main program.
 * Return: 0 when done.
 */

int main(void)
{
	char **args;
	size_t i;
	int inter = isatty(STDIN_FILENO);

	signal(SIGCHLD, sigchld_handler);

	while (1)
	{
		if (inter)
		{

		prompt_loop();
		}

		args = input();

		if (args != NULL  && args[0] != NULL)
		{
			exec_command(args);
		}

		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);

		if (!inter)
		{
			break;
		}
	}

	return (0);
}
