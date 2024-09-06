#include "shell.h"

/**
 * str_len - function that returns string length.
 * @str:  string to check.
 *
 * Return: total length.
 */

int str_len(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}

	return (len);
}
