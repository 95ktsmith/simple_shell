#include "holberton.h"
#include <sys/wait.h>

int main(int argc, char *argv[], char *env[])
{
	char *filepath;
	char **args;
	ssize_t read_bytes;
	pid_t pid;

	if (argc != 1)
	{
		printf("Only 1 arg please thnaks.\n");
		return (-1);
	}

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		args = stdintoargs(&read_bytes);
		if (read_bytes == -1)
			break;
		else if (read_bytes == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(args);
			continue;
		}
		else
		{
			filepath = check_file(args[0], _getenv("PATH", env));
			if (!filepath)
			{
				free(args);
				write(STDOUT_FILENO, "Command not found\n", 18);
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
