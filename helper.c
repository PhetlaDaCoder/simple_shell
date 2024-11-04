#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * _atoi - Function that converts a string to int.
 * @s: Pointer to string.
 * Return: converted string
 */

int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int res = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}

/**
 * _realloc - Function that resizes memory/
 * @ptr: pointer to memory
 * @new_size: pointer to new memory.
 * Return: pointer to new memory.
 */

void *_realloc(void *ptr, size_t new_size)
{
	size_t *old_size_ptr, old_size, copy_size;
	void *new_ptr;

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	old_size_ptr = (size_t *)ptr - 1;
	old_size = *old_size_ptr;

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (ptr);
	}

	if (new_size < old_size)
	{
		copy_size = new_size;
	}
	else
	{
		copy_size = old_size;
	}

	memcpy(new_ptr, ptr, copy_size);

	free(ptr);
	return (new_ptr);
}
