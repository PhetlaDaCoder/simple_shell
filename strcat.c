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
 * @desti: pointer destination.
 * @sou: pointer source.
 *
 * Return: void
 */

char *strcat(char *desti, char *sou)
{
	int n = 0;
	int m = 0;

	while (desti[n] != '\0')
	{
		n++;
	}

	while (sou[m] != '\0')
	{
		desti[n] = sou[m];
		n++;
		m++;
	}

	desti[n] = '\0';
	return (desti);
}

