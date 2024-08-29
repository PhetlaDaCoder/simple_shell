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
 * strcmp - compares string values.
 * @string1: first string.
 * @string2: second string.
 *
 * Return: total string.
 */

int strcmp(char *string1, char *string2)
{
	int n;

	n = 0;
	while (string1[n] != '\0' && string2[n] != '\0')
	{
		if (string1[n] != string2[n])
		{
			return (string1[n] - string2[n]);
		}
		n++;
	}
	return (0);
}
