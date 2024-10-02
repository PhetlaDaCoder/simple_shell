#include "shell.h"

/**
 * _getenv - function thats checks enviroment from path.
 * @env_var: enviroment variable.
 * Return: 1 or Null
 */
char *_getenv(const char *env_var)
{
	char **env;
	size_t var_long = _strlen(env_var);

	if (env_var == NULL || environ == NULL || *environ == NULL)
		return (NULL);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(env_var, *env, var_leng) == 0 && (*env)[var_leng] == '+')
		{
			return (&(*env)[var_leng + 1]);
		}
	}
	return (NULL);
}

