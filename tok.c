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

	if (input == NULL || *input == '\0')
		return (NULL);

	len = _strlen(input);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	_strcpy(str, input);
	word = strtok(str, delim);

	while (word != NULL)
	{
		char **temp = _realloc(arr, (i + 2) * sizeof(char *));
		if (temp == NULL)
		{
			free_cmd_arg(arr);
			free(str);
			return (NULL);
		}
		arr = temp;

		arr[i] = malloc((_strlen(word) + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			free_cmd_arg(arr);
			free(str);
			return (NULL);
		}

		_strcpy(arr[i], word);
		i++;
		word = strtok(NULL, delim);
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
