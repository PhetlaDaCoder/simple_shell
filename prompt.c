#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

/**
 * prompt_loop - prompts user for input
 *
 */

void prompt_loop(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
