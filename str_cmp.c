#include "shell.h"

/**
 * _strcmp - compares two string values.
 * @str1: first string value.
 * @str2: second string value.
 *
 * Return: total sum of strings or NULL.
 *
 */

int _strcmp(char *str1, char *str2)
{
	int a;

	a = 0;

	while (str1[a] != '\0' && str2[a] != '\0')
	{
		if (str1[a] != str2[a])
		{
			return (str1[a] - str2[a]);
		}
		a++;
	}
	return (0);
}
