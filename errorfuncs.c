#include "holberton.h"

/**
 * not_found - file not found
 * Description: Writes a "not found" error message for a command
 * @shellname: The name of the shell. Should be argv[0] from the main function.
 * @cmd_name: Name of the command that was attempted to find and run
 * @cmd_num: Numerical assignment of the command in the history
 * Return: Number of bytes written, or -1 if a write fails.
 */

ssize_t not_found(char *shellname, char *cmd_name, size_t cmd_num)
{
	char buffer[1024], num_str[1024];
	int b_index = 0, t_index;
	char *notfound = "not found\n";

	if (!shellname)
		return (-1);
	if (!cmd_name)
		return (-1);
	for (t_index = 0; shellname[t_index]; t_index++, b_index++)
		buffer[b_index] = shellname[t_index];
	buffer[b_index++] = ':';
	buffer[b_index++] = ' ';

	stoa(cmd_num, num_str, 10);
	for (t_index = 0; num_str[t_index]; t_index++, b_index++)
		buffer[b_index] = num_str[t_index];
	buffer[b_index++] = ':';
	buffer[b_index++] = ' ';
	for (t_index = 0; cmd_name[t_index]; t_index++, b_index++)
		buffer[b_index] = cmd_name[t_index];
	buffer[b_index++] = ':';
	buffer[b_index++] = ' ';
	for (t_index = 0; notfound[t_index]; t_index++, b_index++)
		buffer[b_index] = notfound[t_index];
	buffer[b_index] = 0;
	return (write(STDOUT_FILENO, buffer, _strlen(buffer)));
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

	while(digits < 20)
	{
		if (value < _pow(base, digits))
			break;
		digits++;
	}
	buffer[digits] = 0;

	while(digits--)
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
