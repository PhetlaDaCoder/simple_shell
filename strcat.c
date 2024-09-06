#include "shell.h"

/**
 * str_cat - concatenates stringd.
 * @dest: first string.
 * @src: second string.
 *
 * Return: void
 */

char *str_cat(char *dest, char *src)
{
	int n = 0;
	int m = 0;

	while (dest[n] != '\0')
	{
		n++;
	}

	while (src[m] != '\0')
	{
		dest[n] = src[m];
		n++;
		m++;
	}

	dest[n] = '\0';
	return (dest);
}
