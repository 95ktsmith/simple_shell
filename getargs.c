#include "holberton.h"

/**
 * getline_to_args - standard input to args
 * Description: Reads a line from the standard input and breaks it into tokens
 * @nbytes: A ssize_t pointer that is updated with how many bytes were read
 * @stream: FILE stream to read from
 * @params: Parameter struct
 * Return: A pointer to the array of extracted tokens
 */

char **getline_to_args(ssize_t *nbytes, FILE *stream, param_t *params)
{
	char *buffer;
	size_t buffer_size = 1024;
	char **args;
	int buf_index = 0;

	buffer = malloc(buffer_size);
	if (!buffer)
		clean_exit(params);

	*nbytes = getline(&buffer, &buffer_size, stream);
	if (*nbytes == -1)
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[*nbytes - 1] == '\n')
		buffer[*nbytes - 1] = 0;

	while (buffer[buf_index])
	{
		if (buffer[buf_index] == '#')
		{
			buffer[buf_index] = '\0';
			break;
		}
		buf_index++;
	}
	args = _strtok(buffer, ' ', params);
	free(buffer);

	return (args);
}
