#include "holberton.h"
#include <sys/wait.h>
#include <signal.h>

/**
 * main - entry point
 * Description: Handles the set-up and overall logic flow for the shell.
 * @argc: Number of arguments
 * @argv: Argument vector
 * @env: Environment
 * Return: 0 on success, -1 on failure.
 */
int main(int argc, char *argv[], char *env[])
{
	char *prompt;
	ssize_t read_bytes;
	param_t *params;

	if (argc < 1)
		return (-1);
	params = malloc(sizeof(param_t));
	if (!params)
		return (-1);
	params->shellname = argv[0];
	params->loop_count = 0;
	params->env = env;
	prompt = (_getenv("PS1", env) ? _getenv("PS1", env) : "$ ");
	while (++(params->loop_count))
	{
		signal(2, SIG_IGN);
		if (isatty(STDIN_FILENO) == 1)
		{
			if (write(STDOUT_FILENO, prompt,
				  _strlen(prompt)) != _strlen(prompt))
				clean_exit(params, EXIT_FAILURE);
		}

		params->args = getline_to_args(&read_bytes, stdin, params);
		if (read_bytes == -1)
			break;

		if (params->args != NULL)
			find_and_exec(params);
	}
	free_params(params);
	return (EXIT_SUCCESS);
}
/**
 * find_and_exec - find and execute file
 * Description: Searches for the input command in the list of builtin functions
 *              and executes that function if found. If no matching builtin is
 *              found, it will look through the PATH to find a match, executing
 *              that file if found. If no match is found, it will print an
 *              error.
 * @params: Parameter struct
 * Return: 0 on successful execution of builtin or file PATH, -1 otherwise.
 */
int find_and_exec(param_t *params)
{
	pid_t pid;
	char *filepath;

	if (get_builtin(params->args[0]))
	{
		get_builtin(params->args[0])(params);
		return (0);
	}

	filepath = check_file(params);
	if (filepath)
	{
		free(params->args[0]);
		params->args[0] = filepath;
		pid = fork();
		if (pid == -1)
			clean_exit(params, EXIT_FAILURE);
		if (pid == 0)
		{
			execve(params->args[0], params->args, params->env);
			kill(0, SIGKILL);
		}
		else
			wait(&pid);
		free_array(params->args);
		return (0);
	}

	free_array(params->args);
	return (-1);
}

/**
 * get_builtin - get builtin function
 * Description: Searches the for the input command in the list of builtin
 *              functions.
 * @name: Name of the builtin to look for
 * Return: Pointer to the matching function if found, or NULL if not found.
 */
void (*get_builtin(char *name))(param_t *params)
{
	builtin_t builtins[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL}
	};
	int i = 0;

	while (builtins[i].name)
	{
		if (_strcmp(builtins[i].name, name))
			return (builtins[i].f);
		i++;
	}
	return (NULL);
}
