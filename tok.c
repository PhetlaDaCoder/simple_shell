#include "shell.h"

/**
 * token - Function that splits a string.
 * @input: string to be splited.
 *
 * Return: An array of each string element.
 */

char **token(const char *input)
{
	const char delim[] = " \t\n";
	char *str, *word, **arr;
	size_t len, i;

	len = _strlen(input);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	arr = malloc(sizeof(char *));
	if (arr == NULL)
	{
		free(str);
		return (NULL);
	}

	_strcpy(str, input);
	word = strtok(str, delim);
	for (i = 0; word != NULL; i++)
	{
		arr = _realloc(arr, (i + 1) * sizeof(char *));
		if (arr == NULL)
		{
			free(str);
			return (NULL);
		}

		arr[i] = malloc((_strlen(word) + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			free(str);
			return (NULL);
		}

		_strcpy(arr[i], word);
	}

	if (i == 0)
	{
		free(arr);
		free(str);
		return (NULL);
	}

	arr[i] = NULL;
	free(str);
	return (arr);
}
