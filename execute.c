#include "shell.h"

/**
 * exec - A function that executes commands
 * @argv: array arguments
 * Return: 0 or -1
 */

int exec(char **argv)
{
	char *command = NULL, *command_path = NULL;
	pid_t pid;
	int status;
	char *const env[] = {NULL};

	if (argv)
	{
		command = argv[0];
		command_path = location(command);
		if (command_path == NULL || *command_path == '\0')
		{
			error("command not found", command);
			return (-1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Fork failed");
			return (-1);
		}
		if (pid == 0)
		{
			if (execve(command_path, argv, env) == -1)
			{
				perror("execve");
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status) && (WEXITSTATUS(status) == 127 ||
						WEXITSTATUS(status) == 126))
			{
				error("command not found", command);
			}
			return (WEXITSTATUS(status));
		}
		return (-1);
	}
}
