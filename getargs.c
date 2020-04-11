#include "holberton.h"

/**
 * getline_to_args - standard input to args
 * Description: Reads a line from the standard input and breaks it into tokens
 * @nbytes: A ssize_t pointer that is updated with how many bytes were read
 * @stream: FILE stream to read from
 * Return: A pointer to the array of extracted tokens
 */

char **getline_to_args(ssize_t *nbytes, FILE *stream)
{
	char *buffer;
	size_t buffer_size = 1024;
	char **args;

	buffer = malloc(buffer_size);
	if (!buffer)
		return (NULL);

	*nbytes = getline(&buffer, &buffer_size, stream);
	if (*nbytes == -1)
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[*nbytes - 1] == '\n')
		buffer[*nbytes - 1] = 0;

	args = _strtok(buffer, ' ');
	free(buffer);

	return (args);
}