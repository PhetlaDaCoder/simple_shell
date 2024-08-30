#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * prompt_loop - prompts user for input/
 */

void prompt_loop(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 8);
}
