#include "shell.h"
#include <stdio.h>

/**
 * main - prints a-
 * letter: arguments
 * Return: 0 if successful
 */

int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		printf("%c", letter);
	}

	printf("\n");
	return (0);

}
