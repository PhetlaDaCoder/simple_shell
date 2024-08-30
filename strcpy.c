#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>

/**
 * char *str_cpy - function that copies string.
 * @dest: to destination
 * @src: source to copy from.
 *
 * Return: the string.
 */

char *str_cpy(char *dest, char *src)
{
	int j = 0;
	int i = 0;

	while (*(src + j) != '\0')
	{
		j++;
	}
	for ( ; i < j ; i++)
	{
		dest[i] = src[i];
	}
	dest[j] = '\0';
	return (dest);
}

