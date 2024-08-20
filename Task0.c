#include "main.h"
#include <stdio.h>

/**
 * main - functions that prints from a - z
 * letter: argument
 *
 * Return:0 if success
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
