#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char **args;

	signal(SIGCHLD< sigchld_handler);

	while (1)
	{
		prompt_loop();

		if ((args = input()) && args[0] != NULL)
		{
			exec_command(args);
		}

		for (size_t i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}

	return 0;
}
