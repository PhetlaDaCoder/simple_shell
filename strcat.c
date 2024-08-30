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
 * strcat - joins two strings.
 * @dest: pointer destination.
 * @src: pointer source.
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

