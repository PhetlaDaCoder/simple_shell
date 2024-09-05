#include "shell.h"

/**
 * path_cmd - funcation that locates command in enviroment path.
 * @cmd: pointer to the command.
 *
 * Return: pointer to or NULL.
 */

char *path_cmd(char *cmd)
{
	char *path = NULL, *path_cpy = NULL, *path_token = NULL, *file_path = NULL;

	int command_len = 0, directory_len = 0;

	struct stat buffer;

	path = getenv("PATH");

	if (!path)
	{
		perror("getenv failure");
		return (NULL);
	}

	if (path)
	{
		path_cpy = strdup(path);
		if (path_cpy == NULL)
		{
			perror("strdup failure.");
			return (NULL);
		}

		command_len = str_len(cmd);

		path_token = str_tok(path_cpy, ":");
		while (path_token != NULL)
		{
			directory_len = str_len(path_token);

			file_path = malloc(command_len + directory_len + 2);
			if (!file_path)
			{
				perror("malloc failed");
				return (NULL);
			}
			file_path[command_len + directory_len + 1] = '\0';

			str_cpy(file_path, path_token);
			str_cat(file_path, "/");
			str_cat(file_path, cmd);

			if (stat(file_path, &buffer) == 0)
			{
				return (file_path);
			}

			free(file_path);

			path_token = str_tok(NULL, ":");
		}

		if (stat(cmd, &buffer) == 0)
		{
			return (strdup(cmd));
		}
	}
	return (NULL);
}
