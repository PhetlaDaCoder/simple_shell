#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
 * find_path - finds command listed in path.
 * @cmd: command to find.
 * 
 * Return: Null.
 */

char *find_path(char **cmd)
{
	char *path_env;
	char *path;
	char *dir;
	char full_path[1024];

	path_env = getenv("PATH");

	if (path_env == NULL)
	{
		fprintf(stderr, "PATH not found.\n");
		return (NULL);
	}

	path = strdup(path_env);

	if (path == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	dir = strtok(path, ":");

	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (strdup(full_path));
		}
		dir = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

