#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _strlen - Main program
 * @s: String variable
 *
 * Return: length of string.
 */

int _strlen(const char *s)
{
	int i = 0;

	if (s == NULL)
		return (-1);

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


/**
 * _strcpy - A function that copies strings.
 * @dest: destination
 * @src: Source
 *
 * Return: pointer or Null
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - Main program
 *
 * @dest: Destination
 * @src: Source
 *
 * Return: Pointer or NULL
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr;

	if (dest == NULL || src == NULL)
	{
		write(STDERR_FILENO, "ERROR: NULL pointer detected.\n", 30);
		return (NULL);
	}

	ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';

	return (dest);
}

/**
 * *_strcmp - Main program
 *
 * @s1: First string
 * @s2: Second string
 *
 * Return: 0
 */
int _strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
	}

	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/**
 * *_strdup - Main program
 * @s: String
 *
 * Return: duplicated string
 */
char *_strdup(const char *s)
{
	size_t len;
	char *dup;

	if (s == NULL)
		return (NULL);

	len = _strlen(s) + 1;
	dup = malloc(len);

	if (dup != NULL)
	{
		_strcpy(dup, s);
	}

	return (dup);
}
