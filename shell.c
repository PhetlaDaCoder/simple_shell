#include "shell.h"
#include <string.h>

/**
 * main - a function the calls command line interpreter
 * @x: pointer to interger variable
 * @y: pointer to charecter variable
 * @env: pointer to enviromental variable
 * Return: 0 when done
 */

int main(int x, char **y, char **env)
{
	if (x == 1)
		interpreter(y, env);
	return (0);
}
