#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

/**
 * get_path_copy - copies path enviroment variable.
 *
 * Return: Pointer to copied string of NULL if failed.
 */

char *get_path_copy(void)
{
	char *path = getenv("PATH");
	char *path_cp;

	if (!path)
	{
		perror("getenv failure");
		return (NULL);
	}

	path_cp = strdup(path);
	if (!path_cp)
	{
		perror("strdup failure");
	}

	return (path_cp);
}

/**
 * construct_full_path - constructs path command.
 * @dir: Directory from path.
 * @command: command to locate.
 *
 * Return: pointer to constructed path or NULL if failure.
 */

char *construct_full_path(char *dir, char *command)
{
	char *f_path;
	int comm_len;
	int dir_len;

	comm_len = strlen(command);
	dir_len = strlen(dir);

	f_path = malloc(comm_len + dir_len + 2);
	if (!f_path)
	{
		perror("malloc failure");
		return (NULL);
	}

	strcpy(f_path, dir);
	strcat(f_path, "/");
	strcat(f_path, command);

	return (f_path);
}

/**
 * path_command -a function that locates an enviroment path.
 * @command: command pointer.
 *
 * Return: pointer or NULL
 */

char *path_command(char *command)
{
	char *path_cp;
	char *path_tok;
	char *f_path;
	struct stat buf;

	path_cp = get_path_copy();

	if (!path_cp)
		return (NULL);

	path_tok = find_token(path_cp, ":");
	while (path_tok != NULL)
	{
		f_path = construct_full_path(path_tok, command);
		if (!f_path)
		{
			free(path_cp);
			return (NULL);
		}

		if (stat(f_path, &buf) == 0)
		{
			free(path_cp);
			return (f_path);
		}

		free(f_path);
		path_tok = find_token(&path_cp,  ":");
	}

	free(path_cp);
	return (NULL);
}

