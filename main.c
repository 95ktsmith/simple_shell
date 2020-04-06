#include "holberton.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *env[])
{
	struct stat *buf;
	char *filepath;
	char *filepath2;
	char **path_dirs;
	char *path;
	int index = 0;
	pid_t pid;

	if (argc < 2)
	{
		printf("oop\n");
		return -1;
	}

	buf = malloc(sizeof(struct stat));
	if (!buf)
		return -1;
	path = _getenv("PATH", env);
	path_dirs = _strtok(path, ':');
	if (!path_dirs)
	{
		printf("Error\n");
		free(buf);
		return -1;
	}

	while (path_dirs[index])
	{
		filepath = str_concat(path_dirs[index], "/");
		filepath2 = str_concat(filepath, argv[1]);
		free(filepath);

		if (stat(filepath2, buf) != -1)
		{
			argv[1] = filepath2;
			pid = fork();

			if (pid == 0)
				execve(filepath2, ++argv, env);
			else
			{
				wait(&pid);
				free(filepath2);
				break;
			}
		}
		free(filepath2);
		index++;
	}
	free(buf);
	free_array(path_dirs);
	return 0;
}
