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
 * char *strcpy - function that copies string.
 * @desti: to destination
 * @sou: source to copy from.
 *
 * Return: the string.
 */

char *strcpy(char *desti, char *sou)
{
	int j = 0;
	int i = 0;

	while (*(sou + j) != '\0')
	{
		j++;
	}
	for ( ; i < j ; i++)
	{
		desti[i] = sou[i];
	}
	desti[j] = '\0';
	return (desti);
}

