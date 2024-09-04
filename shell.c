#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

/**
 * exec_command - handles commands.
 * @args: arguments
 */

void exec_command(char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
	}
}

/**
 * sigchld_handler - a function that runs processes.
 * @signum:  argument
 */

void sigchld_handler(int signum)
{
	(void)signum;
	do {

	} while (waitpid(-1, NULL, WNOHANG) > 0);
}


/**
 * main - main loop of the program.
 *
 * Return: 0 when done.
 *
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
			printf("#cisfun$ ");
			fflush(stdout);
		}

		args = prompt_loop();

		if (args != NULL && args[0] != NULL)
		{
			exec_command(args);
		}

		for (i = 0; args != NULL && args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);

		if (inter)
		{
			break;
		}
	}

	return (0);
}

