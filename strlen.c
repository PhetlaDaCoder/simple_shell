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
 * strlen - calculates string length.
 * @string: string value.
 *
 * Return: total length.
 */

int str_len(char *string)
{
	int len = 0;

	while (*string != '\0')
	{
		len++;
		string++;
	}

	return (len);
}
