#include "shell.h"

/**
 * prompt - function that prompts the user.
 */

void prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}
