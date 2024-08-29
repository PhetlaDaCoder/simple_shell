#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * get_line - reads a line from stdin or obj.
 * @line: pointer to charecter.
 * @p: pointter to length of line.
 * @obj: pointer o object.
 *
 * Return: totals chars.
 */

ssize_t get_line(char **line, size_t *p, FILE *obj);
ssize_t get_line(char **line, size_t *p, FILE *obj)
{
	size_t buff = 0;
	ssize_t read = 0;
	int a;

	if (line == NULL || a == NULL)
		return (-1);

	if (*line == NULL || *a == 0)
	{
		buff = BUFFER_SIZE;
		*line = malloc(buff);

		if (*line == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		*p = buff;
	}

	while ((a = fgetc(obj)) != EOF)
	{
		(*line)[read++] = (char)a;

		if (read == (ssize_t)(*p - 1))
		{
			char *tmp = realloc(*line, buff + BUFFER_SIZE);

			if (tmp == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}

			*line = tmp;
			*p += BUFFER_SIZE;
		}

		if (a == '\n')
			break;
	}

	if (read == 0)
		return (0);
	(*line)[read] = '\0';
	return (read);
}
