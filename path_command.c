#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

/**
 * path_command -a function that locates an enviroment path.
 * @com: command pointer.
 *
 * Return: pointer or NULL
 */

char *path_command(char *command)
{
	char *path = NULL, *path_cp = NULL, *f_path = NULL, *path_tok = NULL;
	int comm_len = 0, dir_len = 0;
	struct stat buf;

	path = getenv("PATH");

	if (!path)
	{
		perror("getenv failure");
		return (NULL);
	}


	path_cp = strdup(path);
	if (path_cp == NULL)
	{
		perror("strdup failure");
		return (NULL);
	}

	comm_len =  strlen(command);

	path_tok = strtok(path_cp, ":");
	while (path_tok != NULL)
	{
		dir_len = strlen(path_tok);
		f_path = malloc(comm_len + dir_len + 2);

		if (!f_path)
		{
			perror("malloc failure");
			free(path_cp);
			return(NULL);
		}

		strcpy(f_path, path_tok);
		strcat(f_path, "/");
		strcat(f_path, command);

		if (stat(f_path, &buf) == 0)
		{
			free(path_cp);
			return (f_path);
		}

		free(f_path);
		path_tok = strtok(NULL, ":");
	}

	free(path_cp);
	return (NULL);
}
