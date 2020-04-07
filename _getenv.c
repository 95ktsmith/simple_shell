#include "holberton.h"
#include <sys/stat.h>

/**
 * check_file - check file
 * Description: Checks if a file exists and if the user has execute permissions
 *              Will check the PATH if given just a filename, or just the given
 *              location if given a full path.
 * @filename: Name of the file to check
 * @path: PATH value from the shell env
 * Return: The full path name of the file if it is found and can be executed,
 *         or NULL if either doesn't exist or cannot be executed.
 */
char *check_file(char *filename, char *path)
{

	if (_strchr(filename, '/') != NULL)
	{
		if (access(filename, F_OK | X_OK) == 0)
			return (_strdup(filename));
		else
			return (NULL);
	}
	return (find_in_path(filename, path));
}

/**
 * find_in_path - find a file in the PATH
 * Description: Searches for the location of a file in the PATH
 * @filename: Name of the file to find
 * @path: String containing the PATH from the env variable
 * Return: A pointer to a string containing the full path name of the file
 *         if it is found, or NULL if the file is not found.
 */
char *find_in_path(char *filename, char *path)
{
	int index;
	char **path_dirs;
	char *dirpath, *fullpath;

	path_dirs = _strtok(path, ':');
	if (!path_dirs)
		return (NULL);
	for (index = 0; path_dirs[index]; index++)
	{
		dirpath = str_concat(path_dirs[index], "/");
		if (!dirpath)
		{
			free_array(path_dirs);
			return (NULL);
		}
		fullpath = str_concat(dirpath, filename);
		free(dirpath);
		if (!fullpath)
		{
			free_array(path_dirs);
			return (NULL);
		}

		if (access(fullpath, F_OK | X_OK) == 0)
		{
			free_array(path_dirs);
			return (fullpath);
		}

		free(fullpath);
	}
	free_array(path_dirs);
	return (NULL);
}

/**
 * _getenv - get environment variable
 * Description: Searches the env array of strings for the specified variable
 * @var: The variable to search for
 * @env: Environment
 * Return: A pointer to the first byte following the '=' in that line if the
 *         variable is found, or NULL if it is not found.
 */
char *_getenv(char *var, char **env)
{
	int index = 0;

	while (env[index])
	{
		if (_strstr(env[index], var) != NULL)
			return (_strstr(env[index], var) + _strlen(var) + 1);
		index++;
	}
	return (NULL);
}
