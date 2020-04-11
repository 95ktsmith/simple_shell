#include "holberton.h"
#include <stdarg.h>

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
