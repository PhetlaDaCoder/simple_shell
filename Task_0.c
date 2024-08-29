#include "shell.h"
#include <stdio.h>

/**
 * printAlpha - prints from a to z.
 *
 * Return: 0 if successful.
 */

int printAlpha(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		printf("%c", letter);

	}
	printf("\n");
	return (0);

}
