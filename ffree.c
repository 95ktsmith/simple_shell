#include "holberton.h"
#include <stdarg.h>

/**
 * clean_exit - exit program cleanly
 * Description: Frees everything inside of the parameter struct and exits
 * @params: Parameter struct
 */
void clean_exit(param_t *params)
{
	free_params(params);
	exit(1);
}
/**
 * free_params - free params struct
 * Description: Frees a parameters struct
 * @params: struct to free
 */
void free_params(param_t *params)
{
	if (!params)
		return;
	if (params->args)
		free_array(params->args);
	free(params);
}

/**
 * ffree - formatted free
 * Description: Takes a format string, like printf, and frees given pointers
 *              accordingly, whether they are a single pointer (s), or a double
 *              pointer (d). Double pointers only work with char **s.
 * @fmt: String of format characters that define the pointers to free in order
 */

void ffree(const char *fmt, ...)
{
	va_list pointers;
	int i;

	va_start(pointers, fmt);
	for (i = 0; fmt[i]; i++)
	{
		if (fmt[i] == 's')
			free(va_arg(pointers, void *));
		else if (fmt[i] == 'd')
			free_array(va_arg(pointers, char **));
	}
}

/**
 * free_env - free environment
 * Description: Frees the linked list in which all of the environment values
 *              are stored.
 * @head: Head of the list
 */

void free_env(env_t *head)
{
	if (!head)
		return;

	if (head->next)
		free_env(head->next);

	free(head->val);
	free(head->var);
	free(head);
}
