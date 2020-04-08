#include "holberton.h"
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char *argv[], char *env[])
{
	char *filepath, *prompt;
	char **args;
	size_t loop_count = 0;
	ssize_t read_bytes;
	pid_t pid;

	if (argc != 1)
	{
		printf("Only 1 arg please thnaks.\n");
		return (-1);
	}

	prompt = (_getenv("PS1", env) ? _getenv("PS1", env) : "$ ");
	signal(2, SIG_IGN);
	while (++loop_count)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		args = stdintoargs(&read_bytes);
		if (read_bytes == -1)
			break;
		else if (read_bytes == 1)
		{
			free(args);
			continue;
		}
		else
		{
			filepath = check_file(args[0], _getenv("PATH", env));
			if (!filepath)
			{
				if (_strstr(args[0], "exit"))
				{
					free(args);
					return (0);
				}
				not_found(argv[0], args[0], loop_count);
				free(args);
				continue;
			}
			free(args[0]);
			args[0] = filepath;
			pid = fork();
			if (pid == 0)
				execve(args[0], args, env);
			else
				wait(&pid);
			free(args);
		}
	}
	return (0);
}
