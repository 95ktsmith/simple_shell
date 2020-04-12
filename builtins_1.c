#include "holberton.h"

/**
 * print_env - print environment
 * Description: Prints the environment variables and their values
 * @args: Tokenized arguments from getline
 * @env: Environment
 * @cmd_num: Command number
 */

void print_env(param_t *params)
{
	int index = 0;

	while (params->env[index])
	{
		write(STDOUT_FILENO, params->env[index],
		      _strlen(params->env[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
	free_array(params->args);
}

/**
 * exit_shell - exit shell
 * Description: Exits the shell with given exit status
 * @args: Array of arguments
 * @env: Environment
 * @cmd_num: Command Number
 */
void exit_shell(param_t *params)
{

	free_params(params);
	exit(0);
}
