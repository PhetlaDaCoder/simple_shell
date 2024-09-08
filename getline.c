#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * resize_buffer - resizes buffer.
 * @linepoint: pointer to buffer.
 * @p: pointer to size of buffer.
 *
 * Return: 0 on success, -1 if failed/
 */

static int resize_buffer(char **linepoint, size_t *p)
{
	char *new_linepoint = realloc(*linepoint, *p + BUFFER_SIZE);

	if (new_linepoint == NULL)
	{
		perror("Memory allocation failure");
		free(*linepoint);
		return (-1);
	}
	*linepoint = new_linepoint;
	*p += BUFFER_SIZE;
	return (0);
}

/**
 * init_buffer - initializes buffer if it's NULL or 0.
 * @linepoint: Pointer to buffer.
 * @p: pointer to buffer size.
 * @buf_size: initial buffer size.
 *
 * Return: o when done or -1 if fail.
 */

static int init_buffer(char **linepoint, size_t *p, size_t buf_size)
{
	if (*linepoint == NULL || *p == 0)
	{
		*linepoint = malloc(buf_size);
		if (*linepoint == NULL)
		{
			perror("Memory allocation failed");
			return (-1);
		}
		*p = buf_size;
	}
	return (0);
}

/**
 * read_ch- reads charecter from stream and handles buffer.
 * @linepoint: pointer to buffer.
 * @p: pointer to size of buffer.
 * @ch_read: pointer to the couint of characters read.
 * @stream: file stream to read.
 *
 * Return: 0 when done or -1 if failed.
 */

static int read_ch(char **linepoint, size_t *p, ssize_t *ch_read, FILE *stream)
{
	int ch = fgetc(stream);

	if (ch == EOF)
		return (-1);

	if (*ch_read >= (ssize_t)(*p - 1))
	{
		if (resize_buffer(linepoint, p) == -1)
			return (-1);
	}

	(*linepoint)[(*ch_read)++] = (char)ch;
	return (ch);
}

/**
 * _getline - function that reads from stdin or stream.
 * @linepoint: pointer to char set of the line.
 * @p: pointer to length of line.
 * @stream: pointer to a file object.
 *
 * Return: total characters.
 */

ssize_t _getline(char **linepoint, size_t *p, FILE *stream)
{
	size_t buf_size = BUFFER_SIZE;

	ssize_t ch_read = 0;
	int ch;

	if (linepoint == NULL || p == NULL || stream == NULL)
		return (-1);

	if (init_buffer(linepoint, p, buf_size) == -1)
		return (-1);

	while ((ch = read_ch(linepoint, p, &ch_read, stream)) != EOF)
	{
		if (ch == '\n')
			break;
	}

	if (ch_read == 0 && ch == EOF)
		return (0);

	(*linepoint)[ch_read] = '\0';
	return (ch_read);
}
