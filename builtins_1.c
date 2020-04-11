#include "holberton.h"

/**
 * print_env - print environment
 * Description: Prints the environment variables and their values
 * @args: Tokenized arguments from getline
 * @env: Environment
 * @cmd_num: Command number
 */

void print_env(char *args[], char *env[], size_t cmd_num)
{
	int index = 0;

	while (env[index])
	{
		write(STDOUT_FILENO, env[index], _strlen(env[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
	free_array(args);
}

/**
 * exit_shell - exit shell
 * Description: Exits the shell with given exit status
 * @args: Array of arguments
 * @env: Environment
 * @cmd_num: Command Number
 */
void exit_shell(char *args[], char *env[], size_t cmd_num)
{

	free_array(args);
	exit(0);
}
