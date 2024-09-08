#include "shell.h"

/**
 * file_exists - checks if a file  exists.
 * @file_path: pointer to file path.
 *
 * Return: 0 when done or NULL.
 */

static int file_exists(const char *file_path)
{
	struct stat buffer;

	return (stat(file_path, &buffer) == 0);
}

/**
 * create_file_path - creates path from directort and command.
 * @directory: first argument.
 * @cmd: second argument.
 *
 * Return: file path or NULL.
 */
static char *create_file_path(const char *directory, const char *cmd)
{
	int directory_len = str_len(directory);
	int command_len = str_len(cmd);
	char *file_path = malloc(directory_len + command_len + 2);

	if (!file_path)
	{
		perror("malloc failed");
		return (NULL);
	}

	str_cpy(file_path, directory);
	str_cat(file_path, "/");
	str_cat(file_path, cmd);

	return (file_path);
}

/**
 * path_cmd - funcation that locates command in enviroment path.
 * @cmd: pointer to the command.
 *
 * Return: pointer to or NULL.
 */

char *path_cmd(char *cmd)
{
	char *path = getenv("PATH");
	char *path_cpy = NULL;
	char *path_token = NULL;
	char *file_path = NULL;

	if (!path)
	{
		perror("getenv failure");
		return (NULL);
	}

	path_cpy = strdup(path);
	if (path_cpy == NULL)
	{
		perror("strdup failure");
		return (NULL);
	}

	path_token = str_tok(path_cpy, ":");
	while (path_token != NULL)
	{
		file_path = create_file_path(path_token, cmd);
		if (file_path && file_exists(file_path))
		{
			free(path_cpy);
			return (file_path);
		}
		free(file_path);
		path_token = str_tok(NULL, ":");
	}

	if (file_exists(cmd))
	{
		free(path_cpy);
		return (strdup(cmd));
	}

	free(path_cpy);
	return (NULL);
}
