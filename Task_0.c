#include "shell.h"
#include <stdio.h>

/**
 * a_z - prints from a to z
 * letter: arguments
 * Return: 0 if successful
 */

int a_z(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		printf("%c", letter);
	}

	printf("\n");
	return (0);

}
