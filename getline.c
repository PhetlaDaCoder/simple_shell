#include "shell.h"

#define BUFFER_SIZE 1024

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
	size_t buff = 0;
	ssize_t ch_read = 0;
	int l;

	if (linepoint == NULL || p == NULL)
		return (-1);

	if (*linepoint == NULL || *p == 0)
	{
		buff = BUFFER_SIZE;
		*linepoint = malloc(buff);

		if (*linepoint == NULL)
		{
			perror("Memory allocatin failed");
			exit(EXIT_FAILURE);
		}

		*p = buff;
	}

	while ((l = fgetc(stream)) != EOF)
	{
		(*linepoint)[ch_read++] = (char)l;

		if (ch_read == (ssize_t)(*p - 1))
		{
			char *temp = realloc(*linepoint, buff + BUFFER_SIZE);

			if (temp == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}

			*linepoint = temp;
			*p += BUFFER_SIZE;
		}

		if (l == '\n')
			break;
	}

	if (ch_read == 0)
		return (0);

	(*linepoint)[ch_read] = '\0';
	return (ch_read);
}
