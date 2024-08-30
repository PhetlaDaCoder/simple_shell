#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * handle_memory_error - a function that handles memory error
 */

static void handle_memory_error(void)
{
	perror("Memory allocation failed");
	exit(EXIT_FAILURE);
}

/**
 * allocate_initial_buffer -  allocates buffer for reading a line.
 * @size: Pointer to size of buffer.
 *
 * Return: Pointer to buffer.
 */

static char *allocate_initial_buffer(size_t *size)
{
	char *line;
	*size = BUFFER_SIZE;
	line = malloc(*size);
	if (line == NULL)
	{
		handle_memory_error();
	}

	return (line);
}

/**
 * resize_buffer - a function that handles buffer size.
 * @line: character pointer.
 * @size: first argument
 * @buff: second argument
 */

static void resize_buffer(char **line, size_t *size, size_t *buff)
{
	char *tmp;

	tmp = realloc(*line, *buff + BUFFER_SIZE);

	if (tmp == NULL)
	{
		handle_memory_error();
	}

	*line = tmp;
	*buff += BUFFER_SIZE;
}

/**
 * read_line - A function thats reads a given line.
 * @line: pointer to buffer
 * @size: pointer to the size of buffer.
 * @stream: stream to read from.
 *
 * Return: characters read.
 */

static ssize_t read_line(char **line, size_t *size, FILE *stream)
{
	size_t buff = *size;
	ssize_t read = 0;
	int a;

	while ((a = fgetc(stream)) != EOF)
	{
		(*line)[read++] = (char)a;

		if (read == (ssize_t)(buff - 1))
		{
			resize_buffer(line, size, &buff);
		}

		if (a == '\n')
			break;
	}

	if (read == 0 && a == EOF)
		return (0);

	(*line)[read] = '\0';
	return (read);
}


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
	if (line == NULL)
		return (-1);

	if (*line == NULL || *size == 0)
	{
		*line = allocate_initial_buffer(size);
	}

	return (read_line(line, size, stream));
}
