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
	char **args;
	size_t loop_count = 0;
	ssize_t read_bytes;

	if (argc < 1)
		return (-1);

	prompt = (_getenv("PS1", env) ? _getenv("PS1", env) : "$ ");
	signal(2, SIG_IGN);
	while (++loop_count)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		args = getline_to_args(&read_bytes, stdin);
		if (read_bytes == -1)
			break;
		else if (read_bytes == 1)
		{
			free(args);
			continue;
		}
		else
			find_and_exec(argv, args, env, loop_count);
	}
	return (0);
}
/**
 * find_and_exec - find and execute file
 * Description: Searches for the input command in the list of builtin functions
 *              and executes that function if found. If no matching builtin is
 *              found, it will look through the PATH to find a match, executing
 *              that file if found. If no match is found, it will print an
 *              error.
 * @argv: Argument vector from main
 * @args: Tokenized arguments from stdin or file
 * @env: Environment
 * @cmd_num: Number of commands since the shell was started
 * Return: 0 on successful execution of builtin or file PATH, -1 otherwise.
 */
int find_and_exec(char *argv[], char *args[], char *env[], size_t cmd_num)
{
	char *filepath;
	pid_t pid;

	if (get_builtin(args[0]))
	{
		get_builtin(args[0])(args, env, cmd_num);
		return (0);
	}

	filepath = check_file(args[0], _getenv("PATH", env));
	if (filepath)
	{
		free(args[0]);
		args[0] = filepath;
		pid = fork();
		if (pid == 0)
			execve(args[0], args, env);
		else
			wait(&pid);
		free_array(args);
		return (0);
	}

	write_error(argv[0], args[0], cmd_num, "not found");
	return (-1);
}

/**
 * get_builtin - get builtin function
 * Description: Searches the for the input command in the list of builtin
 *              functions.
 * @name: Name of the builtin to look for
 * Return: Pointer to the matching function if found, or NULL if not found.
 */
void (*get_builtin(char *name))(char *args[], char  *env[], size_t cmd_num)
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
