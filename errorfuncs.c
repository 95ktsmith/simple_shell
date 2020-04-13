#include "holberton.h"

/**
 * write_error - write error message
 * Description: Writes an error message to standard output with details
 *              of the shell name, command number, command name, and a
 *              following message.
 * @params: Parameter struct
 * @msg: Message to write after input details
 * Return: Number of bytes written, or -1 if a write fails.
 */

ssize_t write_error(param_t *params, char *msg)
{
	char buffer[1024], num_str[1024];
	int b_index = 0, t_index;
	ssize_t written_bytes;

	if (!params->shellname)
		return (-1);
	if (!params->args[0])
		return (-1);
	for (t_index = 0; params->shellname[t_index]; t_index++, b_index++)
		buffer[b_index] = params->shellname[t_index];
	buffer[b_index++] = ':';
	buffer[b_index++] = ' ';

	stoa(params->loop_count, num_str, 10);
	for (t_index = 0; num_str[t_index]; t_index++, b_index++)
		buffer[b_index] = num_str[t_index];
	buffer[b_index++] = ':';
	buffer[b_index++] = ' ';
	for (t_index = 0; params->args[0][t_index]; t_index++, b_index++)
		buffer[b_index] = params->args[0][t_index];
	buffer[b_index++] = ':';
	buffer[b_index++] = ' ';
	for (t_index = 0; msg[t_index]; t_index++, b_index++)
		buffer[b_index] = msg[t_index];
	buffer[b_index] = 0;

	written_bytes = write(STDOUT_FILENO, buffer, _strlen(buffer));
	if (written_bytes != _strlen(buffer))
		clean_exit(params);
	return (written_bytes);
}

/**
 * stoa - size_t to alpha
 * Description: Converts a size_t value to a string
 * @value: size_t value to convert
 * @buffer: Buffer to place converted value into
 * @base: Number base to convert to
 */

void stoa(size_t value, char *buffer, size_t base)
{
	size_t digits = 0;

	while (digits < 20)
	{
		if (value < _pow(base, digits))
			break;
		digits++;
	}
	buffer[digits] = 0;

	while (digits--)
	{
		buffer[digits] = (value % base) + '0';
		value /= base;
	}
}

/**
 * _pow - power
 * Description: Raises a number to the power of another
 * @a: First number
 * @b: Second number
 * Return: The result of a raised to the power of b
 */
size_t _pow(size_t a, size_t b)
{
	size_t result = 1;

	while (b--)
		result *= a;
	return (result);
}
