#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char **args;
	size_t i;

	signal(SIGCHLD, sigchld_handler);

	while (1)
	{
		prompt_loop();

		if ((args = input()) && args[0] != NULL)
		{
			exec_command(args);
		}

		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}

	return 0;
}
