#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * location - A function the generates path commands.
 * @command: Pointer to command.
 * Return: comman path.
 */

char *location(char *command)
{
	char *path, *cpy_path, *token_path, *file_path;
	int cmnd_leng, dir_leng;
	struct stat buff;

	path = getenv("PATH");
	if (path == NULL)
	{
		if (stat(command, &buff) == 0)
			return (strdup(command));
		return (NULL);
	}

	cpy_path = strdup(path);
	if (cpy_path == NULL)
		return (NULL);

	cmnd_leng = strlen(command);
	token_path = strtok(cpy_path, ":");

	while (token_path != NULL)
	{
		dir_leng = strlen(token_path);
		file_path = malloc(cmnd_leng + dir_leng + 2);
		if (file_path == NULL)
		{
			free(cpy_path);
			return (NULL);
		}

		strcpy(file_path, token_path);
		strcat(file_path, "/");
		strcat(file_path, command);

		if (stat(file_path, &buff) == 0)
		{
			free(cpy_path);
			return (file_path);
		}
		free(file_path);
		token_path = strtok(NULL, ":");
	}

	free(cpy_path);

	if (stat(command, &buff) == 0)
		return (strdup(command));

	return (NULL);
}
