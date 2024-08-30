#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * get_line - reads a line from stdin or stream.
 *
 * @line: pointer to charecter.
 * @size: pointter to length of line.
 * @stream: pointer o object.
 *
 * Return: totals chars.
 */

ssize_t get_line(char **line, size_t *size, FILE *stream)
{

	size_t buff = 0;
	ssize_t read = 0;
	int a;

	if (line == NULL)
		return (-1);

	if (*line == NULL || *size == 0)
	{
		buff = BUFFER_SIZE;
		*line = malloc(buff);

		if (*line == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		*size = buff;
	}

	while ((a = fgetc(stream)) != EOF)
	{
		(*line)[read++] = (char)a;

		if (read == (ssize_t)(*size - 1))
		{
			char *tmp = realloc(*line, buff + BUFFER_SIZE);

			if (tmp == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}

			*line = tmp;
			*size += BUFFER_SIZE;
		}

		if (a == '\n')
			break;
	}

	if (read == 0 && a == EOF)
		return (0);

	(*line)[read] = '\0';
	return (read);
}
