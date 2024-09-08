#include "shell.h"

/**
 * str_cpy - function that copies strings to a source.
 * @desti: destination to copy from.
 * @src: source to copy from.
 *
 * Return: copied string or -1 if failed.
 */

char *str_cpy(const char *desti, const char *src)
{
	int i;

	int j;

	i = 0;
	j = 0;

	while (*(src + i) != '\0')
	{
		i++;
	}
	for ( ; j < i ; j++)
	{
		desti[j] = src[j];
	}
	desti[i] = '\0';
	return (desti);
}
