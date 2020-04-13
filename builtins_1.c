#include "holberton.h"

/**
 * print_env - print environment
 * Description: Prints the environment variables and their values
 * @params: Parameter struct
 */

void print_env(param_t *params)
{
	int index = 0;
	ssize_t written_bytes;

	while (params->env[index])
	{
		written_bytes = write(STDOUT_FILENO, params->env[index],
		      _strlen(params->env[index]));
		if (written_bytes != _strlen(params->env[index]))
			clean_exit(params);
		written_bytes = write(STDOUT_FILENO, "\n", 1);
		if (written_bytes != 1)
			clean_exit(params);
		index++;
	}
	free_array(params->args);
}

/**
 * exit_shell - exit shell
 * Description: Exits the shell with given exit status
 * @params: Parameter struct
 */
void exit_shell(param_t *params)
{
	int index = 0, status = 0;

	if (params->args[1])
	{
		while (params->args[1][index])
		{
			if (params->args[1][index] < '0' ||
			    params->args[1][index] > '9')
			{
				status = -1;
				break;
			}
			index++;
		}
		if (status == 0)
		{
			index = 0;
			while (params->args[1][index])
			{
				status *= 10;
				status += params->args[1][index] - '0';
				index++;
			}
		}
	}
	if (status < 0 || status > 255)
	{
		write_error(params, "Illegal Number: ");
		if (write(STDOUT_FILENO, params->args[1],
			  _strlen(params->args[1])) != _strlen(params->args[1]))
			clean_exit(params);
		if (write(STDOUT_FILENO, "\n", 1) != 1)
			clean_exit(params);
		return;
	}
	free_params(params);
	exit(status);
}
