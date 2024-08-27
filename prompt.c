#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
 * interpreter - prompts a user to enter a command.
 * Return: 0 when done.
 */

void interpreter(char **x, char **y)
{
	char *str = NULL;
	int num_a, num_b = 0;
	ssize_t holder;
	char *argv[] = (NULL, NULL);
	pid_t ch_pid;

	while (1)
	{
		printf("$");
		holder = getline(str,&num_a, stdin);
		if (holder == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		num_b = 0;
		while (str[num_b])
		{
			if (str[num_b] == '\n')
				str[num_b] = 0;
		}
		ch_pid = fork();
		if (ch_pid == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (ch_pid == 0)
		{
			if (execve(argv[0],argv,y) == -1)
				printf("%s: No such file or dircetory\n", x[0]);

		}
		else
			exit(&status);

	}


}
