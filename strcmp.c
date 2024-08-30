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
 * str_cmp - compares string values.
 * @str1: first string.
 * @str2: second string.
 *
 * Return: total string.
 */

int str_cmp(char *str1, char *str2)
{
	int n;

	n = 0;
	while (str1[n] != '\0' && str2[n] != '\0')
	{
		if (str1[n] != str2[n])
		{
			return (str1[n] - str2[n]);
		}
		n++;
	}
	return (0);
}
