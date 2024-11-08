#include "shell.h"

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
 * _strcpy - Main program
 * @dest: Destination
 * @src: Source
 *
 * Return: Pointer to dest or NULL
 */
char *_strcpy(char *dest, const char *src)
{
	size_t src_len = _strlen(src);
	char *dest_ptr = dest;

	if (src_len >= BUFFER_SIZE)
		return (NULL);

	while ((*dest++ = *src++) != '\0')
	{
		if ((size_t)(dest - dest_ptr) >= BUFFER_SIZE)
			return (NULL);
	}
	return (dest_ptr);
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
	size_t src_len = _strlen(src);
	char *dest_ptr = dest;

	if (dest == NULL ||  src == NULL)
		return (NULL);

	if (src_len >= BUFFER_SIZE)
		return (NULL);

	while ((*dest++ = *src++) != '\0')
	{
		if ((size_t)(dest - dest_ptr) >= BUFFER_SIZE)
			return (NULL);
	}
	return (dest_ptr);
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
	char *ptr = dest;

	if (dest == NULL || src == NULL)
	{
		write(STDERR_FILENO, "ERRor: NULL pointer detected.\n", 30);
		return (dest);
	}

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
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
	if (*s1 == NULL || s2 == NULL)
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

	if (*s1 != *s2)
	{
		return ((unsigned char) *s1 - (unsigned char)*s2);
	}
	return (0);
}

/**
 * *_strdup - Main program
 * @s: String
 *
 * Return: duplicated string
 */
char *_strdup(const char *s)
{
	size_t leng = _strlen(s) + 1;
	char *dup = malloc(leng);

	if (dup != NULL)
	{
		_strcpy(dup, s);
	}

	return (dup);
}
