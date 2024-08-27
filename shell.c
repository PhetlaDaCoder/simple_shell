#include "shell.h"

int main(int x, char **y, char **env)
{
	if (x == 1)
		interpreter(y, env);
	return (0);
}
