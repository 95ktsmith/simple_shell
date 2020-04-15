#include "holberton.h"
#include <sys/stat.h>

/**
 * check_file - check file
 * Description: Checks if a file exists and if the user has execute permissions
 *              Will check the PATH if given just a filename, or just the given
 *              location if given a full path.
 * @params: Parameter struct
 * Return: The full path name of the file if it is found and can be executed,
 *         or NULL if either doesn't exist or cannot be executed.
 */
char *check_file(param_t *params)
{
	char *filepath;

	if (_strchr(params->args[0], '/') != NULL)
	{
		if (access(params->args[0], F_OK | X_OK) == 0)
		{
			filepath = _strdup(params->args[0]);
			if (!filepath)
				clean_exit(params, EXIT_FAILURE);
			return (filepath);
		}
		else
			return (NULL);
	}
	filepath = find_in_path(params);
	if (filepath)
		return (filepath);

	filepath = find_in_pwd(params);
	return (filepath);
}

/**
 * find_in_pwd - find a file in current working directory
 * Description: Searches the current working directory for a file that can
 *              be executed by the user.
 * @params: Parameter struct
 * Return: A pointer to the string containing the full path name of the file
 *         if it is found, or NULL if the file is not found.
 */
char *find_in_pwd(param_t *params)
{
	char *dirpath, *fullpath, *pwd;

	pwd = _getenv("PWD", params->env);
	if (!pwd || _strlen(pwd) < 1)
		return (NULL);

	if (pwd[_strlen(pwd) - 1] != '/')
		dirpath = str_concat(pwd, "/");
	else
		dirpath = _strdup(pwd);
	if (!dirpath)
		clean_exit(params, EXIT_FAILURE);

	fullpath = str_concat(dirpath, params->args[0]);
	free(dirpath);
	if (!fullpath)
		clean_exit(params, EXIT_FAILURE);

	if (access(fullpath, F_OK | X_OK) == 0)
		return (fullpath);

	free(fullpath);
	return (NULL);
}
/**
 * find_in_path - find a file in the PATH
 * Description: Searches for the location of a file in the PATH
 * @params: Parameter struct
 * Return: A pointer to a string containing the full path name of the file
 *         if it is found, or NULL if the file is not found.
 */
char *find_in_path(param_t *params)
{
	int index;
	char **path_dirs;
	char *dirpath, *fullpath;

	path_dirs = _strtok(_getenv("PATH", params->env), ':', params);
	if (!path_dirs)
		return (NULL);
	for (index = 0; path_dirs[index]; index++)
	{
		if (path_dirs[index][_strlen(path_dirs[index]) - 1] != '/')
			dirpath = str_concat(path_dirs[index], "/");
		else
			dirpath = _strdup(path_dirs[index]);
		if (!dirpath)
		{
			free_array(path_dirs);
			clean_exit(params, EXIT_FAILURE);
		}
		fullpath = str_concat(dirpath, params->args[0]);
		free(dirpath);
		if (!fullpath)
		{
			free_array(path_dirs);
			clean_exit(params, EXIT_FAILURE);
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
